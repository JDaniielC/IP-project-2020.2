#include "raylib.h"
#include "config.h"

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
