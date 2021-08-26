#include "raylib.h"
#include "config.h"

#define G 350
#define deslizar 50
#define PLAYER_JUMP_SPD 200.0f
#define PLAYER_HOR_SPD 200.0f
//Passagem secreta voltando no início ele cai
typedef struct Player {
    Vector2 position;
    float speed;
    bool canJump;
    float width;
    float height;
} Player;

typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    int vert;
    Color color;
} EnvItem;

void mostrarTextura(Texture2D esquerdo, Texture2D direito, Texture2D agua, Texture2D chao, Texture2D meio, Texture2D mid, Texture2D objeto, Texture2D parede, Texture2D top) {
    int i, k;
    Rectangle retangulo[] = {
        { 0, 0, 800, 10 },
        { 0, 0, 10, 600 },
        { 798, 0, 10, 600 },
        { 0, 598, 800, 10 },
        {60, 580, 100, 20},
        {180, 520, 100, 20},
        {300, 440, 100, 20},
        {700, 300, 100, 20},
        {500, 400, 100, 20},
        {300, 200, 100, 20},
        {500, 200, 80, 20},
        {180, 280, 40, 20},
        {460, 300, 20, 100},
        {150, 230, 20, 60},
    };
    
    DrawTextureRec(mid, retangulo[0], (Vector2){retangulo[0].x, retangulo[0].y}, WHITE);
    DrawTextureRec(parede, retangulo[1], (Vector2){retangulo[1].x, retangulo[1].y}, WHITE);
    DrawTextureRec(mid, retangulo[3], (Vector2){retangulo[3].x, retangulo[3].y}, WHITE);
    DrawTextureRec(parede, retangulo[2], (Vector2){retangulo[2].x, retangulo[2].y}, WHITE);

    for (k = 4; k < 12; k++) {
        DrawTexture(esquerdo, retangulo[k].x, retangulo[k].y, WHITE);
        for (i = retangulo[k].x+20; i <= retangulo[k].x + retangulo[k].width - 40; i+=20){
            DrawTexture(mid, i, retangulo[k].y, WHITE);
        }
        DrawTexture(direito, retangulo[k].x + retangulo[k].width - 20, retangulo[k].y, WHITE);
    }

    for (k = 12; k < 14; k++) {
        DrawTexture(top, retangulo[k].x, retangulo[k].y, WHITE);
        for (i = retangulo[k].y+20; i < retangulo[k].y + retangulo[k].height; i+=20){
            DrawTexture(meio, retangulo[k].x, i, WHITE);
        }
        DrawTexture(chao, retangulo[k].x, retangulo[k].y + retangulo[k].height, WHITE);
    }

}

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta)
{
    if (IsKeyDown(KEY_LEFT)) player->position.x -= PLAYER_HOR_SPD*delta;
    if (IsKeyDown(KEY_RIGHT)) player->position.x += PLAYER_HOR_SPD*delta;
    if (IsKeyDown(KEY_UP) && player->canJump)
    {
        player->speed = -PLAYER_JUMP_SPD;
        player->canJump = false;
    }

    int hitObstacle = 0;
    for (int i = 0; i < envItemsLength; i++)
    {
        EnvItem *ei = envItems + i;
        Player *p = player;

        if (CheckCollisionRecs((Rectangle){
            p->position.x, p->position.y, p->width, p->height
        }, ei->rect) && (ei->blocking || ei->vert)) {
            hitObstacle = 1;
            player->speed = 0.0f;

            if (ei->rect.x < p->position.x + p->width
                && p->position.x < ei->rect.x) {
                p->position.x = ei->rect.x - p->width;
            }
            else if (p->position.x < ei->rect.x + ei->rect.width
                && ei->rect.x + ei->rect.width < p->position.x + p->width) {
                p->position.x = ei->rect.x + ei->rect.width;
            }
            else if (ei->rect.y < p->position.y + p->height
                && p->position.y < ei->rect.y)
            {
                p->position.y = ei->rect.y - p->height;
            }
            else if (p->position.y < ei->rect.y + ei->rect.height
                && ei->rect.y < p->position.y) {
                p->position.y = ei->rect.y + ei->rect.height;
            }

            // if (ei->blocking && 
            //     ei->rect.x <= p->position.x &&
            //     ei->rect.x + ei->rect.width >= p->position.x &&
            //     ei->rect.y >= p->position.y &&
            //     ei->rect.y < p->position.y + player->speed*delta)
            // {   
            //     hitObstacle = 1;
            //     player->speed = 0.0f;
            //     p->position.y = ei->rect.y;

            // else if (ei->vert) {
            //     hitObstacle = 1;
            //     if (p->position.x <= ei->rect.x) {
            //       player->position.x -= PLAYER_HOR_SPD*delta;  
            //     } 
            //     else player->position.x += PLAYER_HOR_SPD*delta;
            //     if (p->position.y < ei->rect.y + ei->rect.height - 20) player->position.y += deslizar*delta;
            //     // player->speed += G*delta;
                
            // }  
        }

    }

    if (!hitObstacle)
    {
        player->position.y += player->speed*delta;
        player->speed += G*delta;
        player->canJump = false;
    }
    else player->canJump = true;
}

int main(void) {
    const int telaHorizontal = 900;
    const int TelaVertical = 700;
    
    InitWindow(telaHorizontal, TelaVertical, "Joguinho");

    Player player = { 0 };
    player.position = (Vector2){ 50, 550 };
    player.speed = 0;
    player.canJump = false;
    player.height = 20;
    player.width = 20;
    EnvItem envItems[] = {
        {{ 0, 0, 800, 10 }, 1, 0, RED },
        {{ 0, 0, 10, 600 }, 0, 1, RED },
        {{ 798, 0, 10, 600 }, 0, 1, RED },
        {{ 0, 598, 800, 10 }, 1, 0, RED },
        {{50, 580, 100, 20}, 1, 0, BLACK},
        {{180, 520, 100, 20}, 1, 0, BLACK},
        {{310, 440, 100, 20}, 1, 0, BLACK},
        {{450, 300, 20, 100}, 0, 1, BLACK}, 
        {{180, 270, 40, 20}, 1, 0, BLACK}, 
        {{150, 230, 20, 60}, 0, 1, BLACK}, 
        {{500, 200, 70, 20}, 1, 0, BLACK},
        {{700, 300, 100, 20}, 1, 0, BLACK},
        {{500, 400, 100, 20}, 1, 0, BLACK}, 
        {{300, 200, 100, 20}, 1, 0, BLACK}
    };
    int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);

    Texture2D texture = LoadTexture("Assets/character.png");
    Texture2D agua = LoadTexture("Assets/agua.png");
    Texture2D chao = LoadTexture("Assets/chao.png");
    Texture2D direito = LoadTexture("Assets/direito.png");
    Texture2D esquerdo = LoadTexture("Assets/esquerdo.png");
    Texture2D meio = LoadTexture("Assets/meio.png");
    Texture2D mid = LoadTexture("Assets/mid.png");
    Texture2D objeto = LoadTexture("Assets/objeto.png");
    Texture2D parede = LoadTexture("Assets/parede.png");
    Texture2D top = LoadTexture("Assets/top.png");

    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        float deltaTime = GetFrameTime();
        UpdatePlayer(&player, envItems, envItemsLength, deltaTime);
        if (IsKeyPressed(KEY_R)) player.position = (Vector2){30, 570};
        BeginDrawing();
            //Fundo fica brilhando se não escolher a cor
            ClearBackground(RAYWHITE);

            // for (int i = 0; i < envItemsLength; i++) {
            //     DrawRectangleRec(envItems[i].rect, envItems[i].color);
            // }
            // Rectangle playerRect = { 
            //     player.position.x, 
            //     player.position.y, 
            //     player.width, 
            //     player.height 
            // };
            
            DrawTexture(objeto, 550, 550, WHITE);
            DrawTexture(texture, player.position.x, player.position.y, WHITE);

            mostrarTextura(esquerdo, direito, agua, chao, meio, mid, objeto, parede, top);
            
        EndDrawing();
    }
    UnloadTexture(texture);
    UnloadTexture(agua);
    UnloadTexture(chao);
    UnloadTexture(direito);
    UnloadTexture(esquerdo);
    UnloadTexture(meio);
    UnloadTexture(mid);
    UnloadTexture(objeto);
    UnloadTexture(parede);
    UnloadTexture(top);

    CloseWindow();

    return 0;
}