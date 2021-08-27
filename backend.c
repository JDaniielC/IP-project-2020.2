#include "raylib.h"
#include "config.h"
#include <stdio.h>

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
            if (item->trampolim) {
                p->velocidade = -constVertical * 2;
                p->pular = false;
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

void features(Player *player, Feature *recursos, int tam, float delta, int *fase) {
    for (int i = 0; i < tam; i++) {
        Feature *item = recursos + i;
        Player *p = player;

        if (item->bloqueado && CheckCollisionRecs((Rectangle){
            p->posicao.x, p->posicao.y, p->largura, p->altura
        }, item->react)) {
            player->velocidade = 0.0f;

            if (item->react.x < p->posicao.x + p->largura
                && p->posicao.x < item->react.x) {
                player->posicao.x -= constHorizontal*delta;  
                player->posicao.y += deslizar*delta;
                player->velocidade += Gravidade*delta;
            }
            else if (p->posicao.x < item->react.x + item->react.width
                && item->react.x + item->react.width < p->posicao.x + p->largura) {
                player->posicao.x += constHorizontal*delta;
                player->posicao.y += deslizar*delta;
                player->velocidade += Gravidade*delta;
            }
            else if (item->react.y < p->posicao.y + p->altura
                && p->posicao.y < item->react.y)
            {
                p->posicao.y = item->react.y - p->altura;
                p->pular = true;
            }
            else if (p->posicao.y < item->react.y + item->react.height
                && item->react.y < p->posicao.y) {
                p->pular = false;
                p->posicao.y = item->react.y + item->react.height;
            }
        }

        if (item->portal && CheckCollisionRecs((Rectangle){
            p->posicao.x, p->posicao.y, p->largura, p->altura
        }, item->act)) {
            p->posicao.x = item->react.x;
            p->posicao.y = item->react.y;
        }

        if (CheckCollisionRecs((Rectangle){
            p->posicao.x, p->posicao.y, p->largura, p->altura
        }, item->act)) {
            if (item->bloqueado) item->bloqueado = 0;
            else if (item->star) *fase += 1;
        }
    }
}