#include "raylib.h"

#define G 350
#define PLAYER_JUMP_SPD 200.0f
#define PLAYER_HOR_SPD 200.0f

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
        if (ei->blocking && 
            CheckCollisionRecs((Rectangle){p->position.x, p->position.y, p->width, p->height}, ei->rect) &&
            ei->rect.y < p->position.y + player->speed*delta)
        {
            hitObstacle = 1;
            player->speed = 0.0f;
            p->position.y = ei->rect.y;
        }

        if (ei->vert && 
            CheckCollisionRecs((Rectangle){p->position.x, p->position.y, p->width, p->height}, ei->rect)) {
            hitObstacle = 1;
            if (p->position.x <= ei->rect.x) {
                
            }
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
    const int screenWidth = 1000;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "Joguinho");

    Player player = { 0 };
    player.position = (Vector2){ 400, 280 };
    player.speed = 0;
    player.canJump = false;
    player.height = 25;
    player.width = 25;
    EnvItem envItems[] = {
        {{ 0, 0, 800, 2 }, 1, 0, RED },
        {{ 0, 0, 2, 600 }, 0, 1, RED },
        {{100, 560, 100, 10}, 1, 0, GREEN},
        {{400, 300, 100, 10}, 1, 0, GREEN},
        {{400, 350, 100, 10}, 1, 0, GREEN},
        {{400, 500, 20, 100}, 0, 1, GREEN},
        {{ 798, 0, 2, 600 }, 0, 1, RED },
        {{ 0, 598, 800, 2 }, 1, 0, RED }
    };

    int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);

    //Vetor em 2° dimensão, X e Y
    // Vector2 ballposition = {(float)screenWidth/2, (float)screenHeight/2};

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        UpdatePlayer(&player, envItems, envItemsLength, deltaTime);
        
        BeginDrawing();
            //Fundo fica brilhando se não escolher a cor
            ClearBackground(RAYWHITE);

            for (int i = 0; i < envItemsLength; i++) {
                DrawRectangleRec(envItems[i].rect, envItems[i].color);
            }
            Rectangle playerRect = { player.position.x, player.position.y - 25, player.width, player.height };
            DrawRectangleRec(playerRect, RED);
            
            DrawText("LK", 100, 10, 30, PINK);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}