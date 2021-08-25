#include "raylib.h"

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
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Joguinho");

    Player player = { 0 };
    player.position = (Vector2){ 50, 550 };
    player.speed = 0;
    player.canJump = false;
    player.height = 25;
    player.width = 25;
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

    //Vetor em 2° dimensão, X e Y
    // Vector2 ballposition = {(float)screenWidth/2, (float)screenHeight/2};

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        UpdatePlayer(&player, envItems, envItemsLength, deltaTime);
        if (IsKeyPressed(KEY_R)) player.position = (Vector2){30, 570};
        BeginDrawing();
            //Fundo fica brilhando se não escolher a cor
            ClearBackground(RAYWHITE);

            for (int i = 0; i < envItemsLength; i++) {
                DrawRectangleRec(envItems[i].rect, envItems[i].color);
            }
            Rectangle playerRect = { 
                player.position.x, 
                player.position.y, 
                player.width, 
                player.height 
            };
            DrawRectangleRec(playerRect, RED);
            DrawCircle(750, 550, 30, BLUE);
            DrawText("LK", 100, 10, 30, PINK);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}