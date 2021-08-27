#include "raylib.h"
#include "config.h"

void movJogador(Player *player, Plataforma *plataforma, int tamPlataforma, float delta, Vector2 inicial)
{   
    if (IsKeyPressed(KEY_R)) player->posicao = inicial;
    if (IsKeyDown(KEY_LEFT)) player->posicao.x -= constHorizontal*delta;
    if (IsKeyDown(KEY_RIGHT)) player->posicao.x += constHorizontal*delta;
    if (IsKeyDown(KEY_UP) && player->pular)
    {
        player->velocidade = -constVertical;
        player->pular = false;
    }

    int hitObstacle = 0;
    for (int i = 0; i < tamPlataforma; i++)
    {
        Plataforma *item = plataforma + i;
        Player *p = player;

        if (CheckCollisionRecs((Rectangle){
            p->posicao.x, p->posicao.y, p->largura, p->altura
        }, item->rect)) {
            hitObstacle = 1;
            player->velocidade = 0.0f;

            if (item->rect.x < p->posicao.x + p->largura
                && p->posicao.x < item->rect.x) {
                player->posicao.x -= constHorizontal*delta;  
                player->posicao.y += deslizar*delta;
                player->velocidade += Gravidade*delta;
                p->pular = true;
            }
            else if (p->posicao.x < item->rect.x + item->rect.width
                && item->rect.x + item->rect.width < p->posicao.x + p->largura) {
                player->posicao.x += constHorizontal*delta;
                player->posicao.y += deslizar*delta;
                player->velocidade += Gravidade*delta;
                p->pular = true;
            }
            else if (item->rect.y < p->posicao.y + p->altura
                && p->posicao.y < item->rect.y)
            {
                p->posicao.y = item->rect.y - p->altura;
                p->pular = true;
            }
            else if (p->posicao.y < item->rect.y + item->rect.height
                && item->rect.y < p->posicao.y) {
                p->pular = false;
                p->posicao.y = item->rect.y + item->rect.height;
            }
            if (item->mata) {
                p->posicao = inicial;
            }
        }
    }

    if (!hitObstacle)
    {
        player->posicao.y += player->velocidade*delta;
        player->velocidade += Gravidade*delta;
        player->pular = false;
    }
}
