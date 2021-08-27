#include "raylib.h"
#include "config.h"

int main(void) {
    const int telaHorizontal = 800;
    const int TelaVertical = 600;
    int fase = 0;
    
    InitWindow(telaHorizontal, TelaVertical, "Joguinho");

    SetTargetFPS(60);

    Texture2D texturePlayer = LoadTexture("Assets/character.png");

    Player player = { 0 };
    player.posicao = (Vector2){ 50, 550 };
    player.velocidade = 0;
    player.pular = false;
    player.altura = 20;
    player.largura = 20;
    //RED = Morte, BLACK = Comum, GREEN = false, BLUE = Some
    Plataforma plataforma[] = {
        {{ 0, 0, 800, 10 }, 0, 1, 0, RED},
        {{ 0, 0, 10, 600 }, 0, 1, 0, RED},
        {{ 798, 0, 10, 600 }, 0, 1, 0, RED},
        {{ 0, 598, 800, 10 }, 0, 1, 0, RED},
        {{50, 580, 100, 20}, 1, 0, 0, BLACK},
        {{180, 520, 100, 20}, 1, 0, 0, BLACK},
        {{310, 440, 100, 20}, 1, 0, 0, BLACK},
        {{450, 300, 20, 100}, 1, 0, 0, BLACK}, 
        {{180, 270, 40, 20}, 0, 0, 0, BLACK}, 
        {{150, 230, 20, 60}, 0, 0, 0, BLACK}, 
        {{500, 200, 70, 20}, 0, 0, 0, BLACK},
        {{700, 300, 100, 20}, 0, 0, 0, BLACK},
        {{500, 400, 100, 20}, 0, 0, 0, BLACK}, 
        {{300, 200, 100, 20}, 0, 0, 0, BLACK}
    };
    int tamPlataformas = sizeof(plataforma)/sizeof(plataforma[0]);
    Vector2 pontoInicial;

    while(!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        pontoInicial = (Vector2){40, 570};
        movJogador(&player, plataforma, tamPlataformas, deltaTime, pontoInicial);
        DrawTexture(texturePlayer, player.posicao.x, player.posicao.y, WHITE);
        niveis(&fase);
    }
    UnloadTexture(texturePlayer);
    CloseWindow();

    return 0;
}