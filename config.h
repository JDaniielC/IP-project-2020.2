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
    int some;
    int mata;
    int trampolim;
    Color color;
} Plataforma;

#define Gravidade 350
#define deslizar 50
#define constVertical 200.0f
#define constHorizontal 200.0f

void mostrarTextura(Texture2D esquerdo, Texture2D direito, Texture2D agua, Texture2D chao, Texture2D meio, Texture2D mid, Texture2D objeto, Texture2D parede, Texture2D top);

void movJogador(Player *player, Plataforma *plataformas, int tamPlataforma, float delta, Vector2 inicial);

void niveis(int *fase);

#endif