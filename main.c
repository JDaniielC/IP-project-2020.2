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
        //{{Posição e tamanho}, mata, trampolim}
        {{ 0, 0, 800, 10 }, 0, 0}, 
        {{0, 0, 10, 600 }, 0, 0},
        {{798, 0, 10, 600 }, 0, 0},
        {{ 0, 598, 800, 10 }, 0, 0},
        {{60, 580, 100, 20}, 0, 0},
        {{180, 520, 100, 20}, 0, 0},
        {{300, 440, 100, 20}, 0, 0}, 
        {{700, 300, 100, 20}, 0, 0},
        {{500, 400, 100, 20}, 0, 0},
        {{300, 200, 100, 20}, 0, 0},
        {{500, 200, 80, 20}, 0, 0}, 
        {{180, 280, 40, 20}, 0, 0}, 
        {{460, 300, 20, 100}, 0, 0}, 
        {{150, 230, 20, 60}, 0, 0},
    };
    int tamPlataformas = sizeof(plataforma)/sizeof(plataforma[0]);

    Feature recursos[] = {
        //{{Retangulo de ação}, {retangulo de Reação}, bloqueia, objetivo}
        {{700, 550, 20, 20}, {251, 470, 39 , 163}, 0, 1, 0},
        {{60, 250, 40, 40}, {280, 520, 20, 80}, 0, 0, 1},
        {{83, 195, 20, 20}, {122, 60, 100 , 500}, 0, 0, 0},
    };
    int tam = sizeof(recursos)/sizeof(recursos[0]);
    Vector2 pontoInicial;

    while(!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        
        if(fase == 1) {
            pontoInicial = (Vector2){80, 550};
            player.posicao = pontoInicial;
            movJogador(&player, plataforma, tamPlataformas, deltaTime, pontoInicial);
            features(&player, recursos, tam, deltaTime, &fase);
            DrawTexture(texturePlayer, player.posicao.x, player.posicao.y, WHITE);
            niveis(fase, plataforma, recursos);
        
        } else if(fase == 2) {
            pontoInicial = (Vector2){80, 550};
            player.posicao = pontoInicial;
            movJogador(&player, plataforma, tamPlataformas, deltaTime, pontoInicial);
            features(&player, recursos, tam, deltaTime, &fase);
            DrawTexture(texturePlayer, player.posicao.x, player.posicao.y, WHITE);
            niveis(fase, plataforma, recursos);

        } else {
            pontoInicial = (Vector2){80, 550};
            movJogador(&player, plataforma, tamPlataformas, deltaTime, pontoInicial);
            features(&player, recursos, tam, deltaTime, &fase);
            DrawTexture(texturePlayer, player.posicao.x, player.posicao.y, WHITE);
            niveis(fase, plataforma, recursos);
            DrawTextureRec(texturePlayer, (Rectangle){700, 550, 20, 20}, (Vector2){700, 550}, WHITE);
            DrawTextureRec(texturePlayer, (Rectangle){280, 520, 20, 80}, (Vector2){280, 520}, WHITE);
            DrawTextureRec(texturePlayer, (Rectangle){60, 250, 40, 40}, (Vector2){60, 250}, WHITE);

        }
    }
    UnloadTexture(texturePlayer);
    CloseWindow();

    return 0;
}