#ifndef CCONFIG_H
#define CONFIG_H

typedef struct Player {
    Vector2 posicao;
    float velocidade;
    bool pular;
    float largura;
    float altura;
} Player;

typedef struct Plataforma {
    Rectangle rect;
    int mata;
    int trampolim;
} Plataforma;

typedef struct {
    Rectangle act;
    Rectangle react;
    int bloqueado;
    int star;
    int portal;
} Feature;

#define Gravidade 350
#define deslizar 50
#define constVertical 200.0f
#define constHorizontal 200.0f

void mostrarTextura(Texture2D *nivel, Plataforma *plat, Feature *recursos);

void mostrarTextura1(Texture2D *nivel1, Plataforma *plat, Feature *recursos);

void mostrarTextura2(Texture2D *nivel2, Plataforma *plat, Feature *recursos);

void movJogador(Player *player, Plataforma *plataformas, int tamPlataforma, float delta, Vector2 inicial);

void niveis(int fase, Plataforma *plat, Feature *recursos);

void features(Player *player, Feature *recursos, int tam, float delta, int *fase);

#endif