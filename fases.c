#include "raylib.h"
#include "config.h"

void mostrarTextura(Texture2D *nivel, Plataforma *plat, Feature *recursos) {
    int i, j;
        //tutorial 
    DrawTexture(nivel[20], 10, 542, WHITE);
    DrawTexture(nivel[23], 90, 542, WHITE);

    for(i=0; i<240;i+=20){
        for(j=560; j<600;j+=20){
            if(j==560) DrawTexture(nivel[10], i, j, WHITE);
            else DrawTexture(nivel[11], i, j, WHITE);
        }
    }

    for (i = 240; i < 800; i+= 20) {
        for (j = 580; j < 600; j+=20) {
            DrawTexture(nivel[12], i, j, WHITE);
        }
    }

    DrawTexture(nivel[22], 340, 542, WHITE);
    for(i=320; i< 440; i+=20){
        for(j=560; j<600; j+=20){
            if(j==560) DrawTexture(nivel[10], i, j, WHITE);
            else DrawTexture(nivel[11], i, j, WHITE);
        }
    }

    for(i=520; i<640; i+=20){
        for(j=560; j<640; j+=20){
            if(j==560 && i<600) DrawTexture(nivel[10], i, j, WHITE);
            else DrawTexture(nivel[11], i, j, WHITE);
        }
    }

    for(i=600; i<640; i+=20){
        for(j=400; j<580; j+=20){
            if(j!=400) DrawTexture(nivel[11], i, j, WHITE);
            else DrawTexture(nivel[10], i, j, WHITE);
        }
    }

    for(i= 400; i<460; i+=20){
        for(j=400; j<420; j+=20){
            if(i==400) DrawTexture(nivel[13], i, j, WHITE);
            else if(i==420) DrawTexture(nivel[14], i, j, WHITE);
            else DrawTexture(nivel[15], i, j, WHITE);
        }
    }

    for(i=200; i<320; i+=20){
        for(j=400; j<440; j+=20){
            DrawTexture(nivel[16], i, j, WHITE);
        }
    }

    for(i=160; i<240; i+=20){
        for(j=360; j<400; j+=20){
            DrawTexture(nivel[16], i, j, WHITE);
        }
    }

    for(i=160; i<200; i+=20){
        for(j=280; j<360; j+=20){
            DrawTexture(nivel[16], i, j, WHITE);
        }
    }

    for(i=80; i<200; i+=20){
        for(j=280; j<320; j+=20){
            DrawTexture(nivel[16], i, j, WHITE);
        }
    }

    for(i=80; i<120; i+=20){
        for(j=200; j<280; j+=20){
            DrawTexture(nivel[16], i, j, WHITE);
        }
    }

    for(i=0; i<120; i+=20){
        for(j=200; j<240; j+=20){
            DrawTexture(nivel[16], i, j, WHITE);
        }
    }
    
    if (recursos[1].bloqueado) {
        DrawTexture(nivel[19], 40, 160, WHITE);
        for(i=600; i<640; i+=20){
            for(j=0; j<400; j+=20){
                DrawTexture(nivel[17], i, j, WHITE);
            }
        }
    }

    DrawTexture(nivel[18], 710, 520, WHITE);
}

void mostrarTextura1(Texture2D *nivel1, Plataforma *plat, Feature *recursos) {
    DrawRectangle(0, 560, 400, 40, WHITE);
    DrawRectangle(160, 520, 40, 40, WHITE);
    DrawRectangle(200, 480, 40, 40, RED);
    DrawRectangle(240, 440, 40, 40, WHITE);
    DrawRectangle(280, 400, 120, 40, WHITE);
    DrawRectangle(360, 440, 40, 120, LIGHTGRAY);
    DrawRectangle(360, 240, 40, 160, WHITE);
    DrawRectangle(120, 240, 120, 40, WHITE);
    DrawRectangle(80, 240, 40, 200, WHITE);
    DrawRectangle(0, 400, 80, 40, RED);
    DrawRectangle(80, 120, 40, 120, LIGHTGRAY);
    DrawRectangle(0, 80, 540, 40, WHITE);
    DrawRectangle(520, 560, 200, 40, WHITE);
    DrawRectangle(720, 560, 80, 40, DARKBLUE);
    DrawRectangle(680, 80, 40, 440, WHITE);
    DrawRectangle(720, 80, 80, 40, RED);
    DrawRectangle(720, 480, 80, 40, LIGHTGRAY);
    DrawRectangle(0, 0, 1, 600, WHITE);
    DrawRectangle(799 , 0, 1, 600, WHITE);
}

void mostrarTextura2(Texture2D *nivel2, Plataforma *plat, Feature *recursos) {
    DrawText("Fase 2", 10, 10, 50, PINK);
    //desenhando os retângulos
    // DrawRectangle(x, y, largura, altura, cor);
    //está basicamente na ordem de onde o player passa
    DrawRectangle(80, 560, 120, 40, WHITE);
    DrawRectangle(200, 520,160, 40, WHITE);
    DrawRectangle(200, 444, 160, 40, WHITE);
    DrawRectangle(400, 200, 40, 320, WHITE);
    DrawRectangle(520, 200, 80, 40, WHITE);
    DrawRectangle(560, 240, 20, 280, WHITE);
    DrawRectangle(580, 240, 20, 280, RED);
    DrawRectangle(640, 160, 20, 360, RED);
    DrawRectangle(660, 160, 20, 360, WHITE);
    DrawRectangle(600, 560, 160, 40, WHITE);
    DrawRectangle(760, 560, 40, 40, RED);
    DrawRectangle(720, 320, 40, 240, WHITE);
    DrawRectangle(760, 320, 40, 40, GREEN);
    DrawRectangle(560, 120, 120, 40, WHITE);
    DrawRectangle(550, 120, 40, 40, RED);
    DrawRectangle(440, 120, 110, 40, WHITE);
    DrawRectangle(400, 120, 40, 40, WHITE);
    DrawRectangle(360, 120, 40, 40, WHITE);
    DrawRectangle(280, 120, 80, 40, GREEN);
    DrawRectangle(160, 120, 40, 40, GREEN);
    DrawRectangle(200, 120, 80, 40, WHITE);
    DrawRectangle(440, 30, 80, 40, RED);
    DrawRectangle(200, 40, 40, 40, RED);
    DrawRectangle(80, 160, 40, 160, WHITE);
    DrawRectangle(40, 280, 40, 40, YELLOW); //objetivo
    DrawRectangle(0,280, 40, 40, WHITE);
}

void niveis(int fase, Plataforma *plat, Feature *recursos){
    //Carregar assets
    Texture2D agua = LoadTexture("Assets/agua.png");
    Texture2D chao = LoadTexture("Assets/chao.png");
    Texture2D chao1 = LoadTexture("Assets/chao1.png");
    Texture2D chao2 = LoadTexture("Assets/chao2.png");
    Texture2D direito = LoadTexture("Assets/direito.png");
    Texture2D esquerdo = LoadTexture("Assets/esquerdo.png");
    Texture2D meio = LoadTexture("Assets/meio.png");
    Texture2D mid = LoadTexture("Assets/mid.png");
    Texture2D objeto = LoadTexture("Assets/objeto.png");
    Texture2D parede = LoadTexture("Assets/parede.png");
    Texture2D top = LoadTexture("Assets/top.png");
    Texture2D espinhos = LoadTexture("Assets/espinhos.png");
    Texture2D nuvem1 = LoadTexture("Assets/nuvem1.png");
    Texture2D nuvem2 = LoadTexture("Assets/nuvem2.png");
    Texture2D nuvem3 = LoadTexture("Assets/nuvem3.png");
    Texture2D chaoCeu = LoadTexture("Assets/chaoCeu.png");
    Texture2D arvore = LoadTexture("Assets/plataformaSome.png");
    Texture2D portal = LoadTexture("Assets/objeto.png");
    Texture2D chave = LoadTexture("Assets/Objetivo.png");
    Texture2D start = LoadTexture("Assets/start.png");
    Texture2D cacto = LoadTexture("Assets/cacto.png");
    Texture2D right = LoadTexture("Assets/right.png");
    Texture2D cogumelo = LoadTexture("Assets/cogumelo.png");
    
    if(fase == 1){
        Texture2D nivel1[] = {
            agua, chao, direito, esquerdo, meio, mid, objeto, parede, top
        };
        BeginDrawing();//comeca a desenhar fase 1
            ClearBackground(BLACK);
            mostrarTextura1(nivel1, plat, recursos);
        EndDrawing();//final da fase 1
        
    }
    else if(fase == 2){
        Texture2D nivel2[] = {
            agua, chao, direito, esquerdo, meio, mid, objeto, parede, top
        };
        BeginDrawing();//comeca fase 2
            ClearBackground(BLACK);
            mostrarTextura2(nivel2, plat, recursos);
        EndDrawing();// termina fase 2
    }
    else {
        //O que está enviando:
// agua[0], chao[1], direito[2], esquerdo[3], meio[4], mid[5], objeto[6], parede[7], top[8], fundo[9], chao2[10], chao1[11], espinhos[12], nuvem1[13], chaoCeu[16], arvore[17], portal[18],chave[19],start[20], cacto[21], right[22]
        Texture2D nivel[] = {
            agua, chao, direito, esquerdo, meio, mid, objeto, parede, top, top,chao2, chao1, espinhos, nuvem1, nuvem2, nuvem3, chaoCeu, arvore, portal, chave, start, cacto, right, cogumelo
        };
        BeginDrawing();//fase inicial 
            ClearBackground(BLACK);
            mostrarTextura(nivel, plat, recursos);
        EndDrawing();
        // final fase inicial
    }
    //Descarregar assets
    UnloadTexture(agua);     UnloadTexture(chao);
    UnloadTexture(direito);  UnloadTexture(esquerdo);
    UnloadTexture(meio);     UnloadTexture(mid);
    UnloadTexture(objeto);   UnloadTexture(parede);
    UnloadTexture(top);      
    UnloadTexture(chao2);    UnloadTexture(chao1);
    UnloadTexture(espinhos); UnloadTexture(nuvem1);
    UnloadTexture(nuvem2);   UnloadTexture(nuvem3);
    UnloadTexture(chaoCeu);  UnloadTexture(arvore);
    UnloadTexture(portal);   UnloadTexture(start);
    UnloadTexture(cacto);    UnloadTexture(right);
}