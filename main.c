#include "raylib.h"
#include "config.h"

int main(void) {
    const int telaHorizontal = 800;
    const int TelaVertical = 600;
    int fase = 1;
    
    InitWindow(telaHorizontal, TelaVertical, "Joguinho");

    SetTargetFPS(60);

    Texture2D texturePlayer = LoadTexture("Assets/character.png");
    Texture2D fundo = LoadTexture("Assets/fundo.png");
    Vector2 pontoInicial;

    Player player = { 0 };
    player.posicao = (Vector2){ 50, 550 };
    player.velocidade = 0;
    player.pular = false;
    player.altura = 20;
    player.largura = 20;

    Plataforma plataforma[] = {
        //{{Posição e tamanho}, mata, trampolim}
        {{0, 560, 240, 40}, 0, 0}, 
        {{320, 560, 120, 40}, 0, 0},
        {{520, 560, 120, 40}, 0, 0},
        {{600, 400, 40, 160}, 0, 0},
        {{200, 400, 120, 40}, 0, 0},
        {{160, 360, 80, 40}, 0, 0},
        {{160, 281, 40, 80}, 0, 0},
        {{80, 280, 120, 40}, 0, 0},
        {{80, 201, 40, 80}, 0, 0},
        {{0, 200, 120, 40}, 0, 0},
        {{240, 590 ,600 ,10}, 1, 0},
        {{-300, 600, 300, 30}, 1, 0},
    };
    int tamPlataformas = sizeof(plataforma)/sizeof(plataforma[0]);

    Feature recursos[] = {
        //{{Retangulo de ação}, {retangulo de Reação}, bloqueia, objetivo, portal}
        {{710, 520, 20, 20}, {251, 470, 39 , 163}, 0, 1, 0},
        {{40, 160, 20, 20}, {600, 0, 40, 400}, 1, 0, 0},
    };
    int tam = sizeof(recursos)/sizeof(recursos[0]);

    Plataforma plataforma1[] = {
        {{0, 560, 400, 40} ,0 ,0},
        {{160, 520, 40, 40} ,0 ,0},
        {{200, 480, 40, 40} ,0 ,1},
        {{240, 440, 50, 40},0, 0},
        {{280, 400, 120, 40},0 ,0},
        {{360, 440, 40, 120},0 ,0},
        {{360, 240, 40, 160},0 ,0},
        {{110, 240, 130, 40},0 ,0},
        {{80, 240, 40, 200},0 ,0},
        {{0, 400, 80, 40},0 ,0},
        {{80, 120, 40, 120},0 ,0},
        {{0, 80, 540, 40},0 ,0},
        {{520, 560, 220, 40},0 ,0},
        {{720, 560, 80, 40},0 ,0},
        {{680, 80, 40, 440},0 ,0},
        {{700, 80, 100, 40},0 ,1},
        {{600, 0, 40, 400},0,0},
        {{720, 480, 80, 40},0 ,0},
        {{0, 0, 1, 600}, 0, 1},
        {{799 , 0, 1, 600}, 0, 1},
    };
    int tamPlat1 = sizeof(plataforma1)/sizeof(plataforma1[0]);

    Plataforma plataforma2[] ={
        {{80, 560, 130, 40},0,0},
        {{200, 520,160, 40},0,0},
        {{200, 444, 160, 40},0,0},
        {{550, 120, 60, 40},1,0},
        {{520, 200, 80, 40},0,0},
        {{320, 120, 120, 40},0,0},
        {{200, 120, 80, 40},0,0},
        {{560, 120, 120, 40},0,0},
        {{440, 40, 80, 40},1,0},
        {{600, 560, 160, 40},0,0},
        {{440, 120, 110, 40},0,0},
        {{720, 320, 40, 240},0,0},
        {{400, 200, 40, 320},0,0},
        {{560, 240, 20, 280},0,0},
        {{580, 240, 20, 280},1,0},
        {{640, 160, 20, 360},1,0},
        {{660, 160, 20, 360},0,0},
        {{80, 160, 40, 160},0,0},
        {{400, 120, 40, 40},0,0},
        {{760, 560, 40, 40},1,0},
        {{200, 40, 40, 40},1,0},
        {{0,280, 40, 40},0,0},
        //{{40, 280, 40, 40, }},
        //{{280, 120, 40, 40,},1,0},
        //{{160, 120, 40, 40,},},plataforma falsa
        // {{760, 320, 40, 40,},},plataforma falsa.
    };
    int tamPlat2 = sizeof(plataforma2)/sizeof(plataforma2[0]);

    Feature recurso2[] = {
        {{0, 0, 0, 0}, {0, 0, 0, 0}, 0, 0, 0},
    };
    int tam2 = sizeof(recurso2)/sizeof(recurso2[0]);

    while(!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        
        if(fase == 1) {
            pontoInicial = (Vector2){80, 500};
            movJogador(&player, plataforma, tamPlataformas, deltaTime, pontoInicial);
            //features(&player, recursos, tam, deltaTime, &fase);
            DrawTexture(texturePlayer, player.posicao.x, player.posicao.y, WHITE);
            niveis(fase, plataforma, recursos);
        
        } else if(fase == 2) {
            pontoInicial = (Vector2){500, 400};
            movJogador(&player, plataforma, tamPlataformas, deltaTime, pontoInicial);
            // features(&player, recurso2, tam2, deltaTime, &fase);
            DrawTexture(texturePlayer, player.posicao.x, player.posicao.y, WHITE);
            niveis(fase, plataforma2, recursos);

        } else {
            pontoInicial = (Vector2){20, 540};
            movJogador(&player, plataforma, tamPlataformas, deltaTime, pontoInicial);
            features(&player, recursos, tam, deltaTime, &fase);
            DrawTexture(fundo, fundo.width/800, fundo.height/500, LIGHTGRAY);
            DrawTexture(texturePlayer, player.posicao.x, player.posicao.y, WHITE);
            niveis(fase, plataforma, recursos);
        }
    }
    UnloadTexture(texturePlayer);
    UnloadTexture(fundo);
    CloseWindow();

    return 0;
}