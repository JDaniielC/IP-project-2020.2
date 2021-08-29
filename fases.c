#include "raylib.h"
#include "config.h"

void mostrarTextura(Texture2D *nivel, Plataforma *plat, Feature *recursos) {
    int i, j;
        //tutorial 
    DrawTexture(nivel[20], 10, 542, WHITE);
    DrawTexture(nivel[23], 90, 542, WHITE);

    // agua[0], chao[1], direito[2], esquerdo[3], meio[4], mid[5], objeto[6], parede[7], top[8], fundo[9], chao2[10], chao1[11], espinhos[12], nuvem1[13], chaoCeu[16], arvore[17], portal[18],chave[19],start[20], cacto[21], right[22]

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
    int i, j;

    DrawTexture(nivel1[11], nivel1[11].width/400, nivel1[11].height/200, LIGHTGRAY); 

    for(i=0; i<400; i+=20){
        for(j=560; j<600; j+=20){
            if(j==560 && i!=360 && i!=380)
            DrawTexture(nivel1[10], i, j, WHITE);
            else
            DrawTexture(nivel1[9], i, j, WHITE);
        }
    }

    for(i= 160; i<200; i+=20){
        for(j=520; j<560; j+=20){
            if(j==520)
            DrawTexture(nivel1[10], i, j, WHITE);
            else
            DrawTexture(nivel1[9], i, j, WHITE);
        }
    }

    for(i=200; i<240; i+=20){
        for(j=480; j<520; j+=20){
            if(j==480){
                DrawTexture(nivel1[10], i, j, WHITE);
            }
            else
                DrawTexture(nivel1[9], i, j, WHITE);
        }
    }

    DrawTexture(nivel1[17], 210, 462, WHITE);

    for(i=240; i<280; i+=20){
        for(j= 440; j<480; j+=20){
            if(j==440)
                DrawTexture(nivel1[10], i, j, WHITE);
            else
                DrawTexture(nivel1[9], i, j, WHITE);
        }
    }

    for(i=280; i<360; i+=20){
        for(j= 400; j<440; j+=20){
            if(j==400)
                DrawTexture(nivel1[10], i, j, WHITE);
            else
                DrawTexture(nivel1[9], i, j, WHITE);
        }
    }

    for(i=360; i<400; i+=20){
        for(j= 400; j<560; j+=20){
                DrawTexture(nivel1[9], i, j, WHITE);
        }
    }
    
    for(i=360; i<400; i+=20){
        for(j= 240; j<400; j+=20){
                if(j==240)
                DrawTexture(nivel1[10], i, j, WHITE);
                else
                DrawTexture(nivel1[9], i, j, WHITE);
        }
    }
    
    for(i=120; i<240; i+=20){
        for(j= 240; j<280; j+=20){
                DrawTexture(nivel1[12], i, j, WHITE);
        }
    }
    
    for(i=80; i<120; i+=20){
        for(j= 240; j<440; j+=20){
                DrawTexture(nivel1[12], i, j, WHITE);
        }
    }
    
    for(i=0; i<80; i+=20){
        for(j= 400; j<440; j+=20){
                DrawTexture(nivel1[12], i, j, WHITE);
        }
    }
    
    for(i=80; i<120; i+=20){
        for(j=120; j<240; j+=20){
            if(j==220){
                DrawTexture(nivel1[15], i, j, WHITE);
            }
            else
                DrawTexture(nivel1[16], i, j, WHITE);
        }
    }
    
    for(i=0; i<540; i+=20){
        for(j=80; j< 120; j+=20){
            DrawTexture(nivel1[12], i, j, WHITE);
        }
    }
    
    for(i=520; i<720; i+=20){
        for(j=560; j< 600; j+=20){
            if(j==560)
                DrawTexture(nivel1[10], i, j, WHITE);
                else
                DrawTexture(nivel1[9], i, j, WHITE);
        }
    }
    
    for(i=720; i<800; i+=18){
        for(j=560; j< 600; j+=18){
            if(j==560)
                DrawTexture(nivel1[0], i, j, WHITE);
            else
                DrawTexture(nivel1[13], i, j, WHITE);
        }
    }
    
    for(i=680; i<720; i+=20){
        for(j=80; j< 520; j+=20){
            DrawTexture(nivel1[12], i, j, WHITE);
        }
    }
    
    for(i=720; i<800; i+=20){
        for(j=80; j< 100; j+=20){
            if(i==740)
            DrawTexture(nivel1[14], i, j, WHITE);
        }
    }
    
    for(i=720; i<800; i+=20){
        for(j=480; j< 520; j+=20){
            DrawTexture(nivel1[12], i, j, WHITE);
        }
    }
    
    for(i=0; i<1; i++){
        for(j=0; j<600; j+=20){
            DrawTexture(nivel1[12], i, j, WHITE);
        }
    }
    
    for(i=780; i<800; i+=20){
        for(j=0; j<600; j+=20){
            DrawTexture(nivel1[12], i, j, WHITE);
        }
    }
}

void mostrarTextura2(Texture2D *nivel2, Plataforma *plat, Feature *recursos) {
    int i, j;
    DrawText("Fase 2", 10, 10, 50, PINK);

    // agua[0], contornoE[1], contornoD[2], chao2[3], CBE[4], CBM[5], CBD[6]
    for (i = 0; i < 40; i++) DrawTexture(nivel2[0], i*20, 582, WHITE);
    DrawTexture(nivel2[1], 80, 560, WHITE);
    for (i = 100; i < 180; i+= 20) DrawTexture(nivel2[3], i, 560, WHITE);
    DrawTexture(nivel2[2], 180, 560, WHITE);
    DrawTexture(nivel2[4], 80, 580, WHITE);
    for (i = 100; i < 180; i+= 20) DrawTexture(nivel2[5], i, 580, WHITE);
    DrawTexture(nivel2[6], 180, 580, WHITE);
    
    //chaoCeu[7], cordaEsq[8], cordaMeio[9], cordaDir[10], bandeira[11]
    for (i = 200; i < 360; i+= 20) {
        for (j = 520; j < 550; j+= 20)
            DrawTexture(nivel2[7], i, j, WHITE);
    }
    for (i = 200; i < 360; i+= 20) {
        for (j = 444; j < 480; j+= 20)
            DrawTexture(nivel2[7], i, j, WHITE);
    }
    
    for (i = 200; i < 580; i+= 20) DrawTexture(nivel2[9], i, 560, WHITE);
    DrawTexture(nivel2[8], 201, 560, WHITE);
    DrawTexture(nivel2[10], 580, 560, WHITE);
    DrawTexture(nivel2[11], 80, 542, WHITE);

    DrawRectangle(400, 200, 40, 320, WHITE);
    DrawRectangle(520, 200, 80, 40, WHITE);
    DrawRectangle(560, 240, 20, 280, WHITE);
    DrawRectangle(660, 160, 20, 360, WHITE);

    for (i = 600; i < 760; i+= 20) {
        for (j = 560; j < 600; j+= 20) 
            DrawTexture(nivel2[12], i, j, WHITE);
    } 

    for (i = 720; i < 750; i+= 20) {
        for (j = 320; j < 550; j+= 20) 
            DrawTexture(nivel2[12], i, j, WHITE);
    } 

    DrawCircle(780, 500, 14, BLUE);         //portal troca de fase

    DrawRectangle(760, 320, 40, 40, GRAY);

    // esquerdo[13], meio[14], direito[15], espinhoE[16], espinhoD[17], espinhos[18], espinhoB[19]
    DrawTexture(nivel2[13], 160, 120, WHITE);
    for (i = 160; i < 660; i+= 20) DrawTexture(nivel2[14], i, 120, WHITE);
    DrawTexture(nivel2[15], 660, 120, WHITE);
    DrawTexture(nivel2[4], 160, 140, WHITE);
    for (i = 160; i < 670; i+= 20) DrawTexture(nivel2[5], i, 140, WHITE);
    DrawTexture(nivel2[6], 660, 140, WHITE);
    
    for (i = 550; i < 610; i += 20) {
        DrawTexture(nivel2[18], i, 100, WHITE);
        DrawTexture(nivel2[19], i, 158, WHITE);
    }
    for (i = 580; i < 600; i+=20) {
        for (j = 240; j < 520; j += 20) {
            DrawTexture(nivel2[16], i, j, WHITE);
        }
    }

    for (i = 640; i < 660; i+=20) {
        for (j = 160; j < 520; j += 20) {
            DrawTexture(nivel2[17], i, j, WHITE);
        }
    }

    DrawRectangle(440, 40, 80, 40, RED);
    DrawRectangle(200, 40, 40, 40, RED);
    DrawRectangle(80, 160, 40, 160, WHITE);
    DrawRectangle(40, 280, 40, 40, YELLOW);//objetivo
    DrawRectangle(0,280, 40, 40, WHITE);
    DrawRectangle(20,60, 20, 20, YELLOW);

    DrawTexture(nivel2[20], 10, 90, WHITE);

    DrawRectangle(440,510,120,10, RED);
}

void final() {
    DrawText("Parabéns abençoado", 30, GetScreenHeight()/2, 70, PINK);
}

void niveis(int fase, Plataforma *plat, Feature *recursos){
    //Carregar assets
    Texture2D chao1 = LoadTexture("Assets/chao1.png");
    Texture2D chao2 = LoadTexture("Assets/chao2.png");
    Texture2D objeto = LoadTexture("Assets/objeto.png");
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
    
    Texture2D parede = LoadTexture("Assets/parede.png");
    Texture2D esquerdo = LoadTexture("Assets/esquerdo.png");
    Texture2D meio = LoadTexture("Assets/meio.png");
    Texture2D direito = LoadTexture("Assets/direito.png");
    Texture2D agua = LoadTexture("Assets/agua.png");
    Texture2D chao = LoadTexture("Assets/chao.png");
    Texture2D cordaEsq = LoadTexture("Assets/esqCorda.png");
    Texture2D cordaMeio = LoadTexture("Assets/midCorda.png");
    Texture2D cordaDir = LoadTexture("Assets/dirCorda.png");
    Texture2D one = LoadTexture("Assets/1.png");
    Texture2D two = LoadTexture("Assets/2.png");
    Texture2D three = LoadTexture("Assets/3.png");
    Texture2D four = LoadTexture("Assets/4.png");
    Texture2D five = LoadTexture("Assets/5.png");
    Texture2D six = LoadTexture("Assets/6.png");
    Texture2D seven = LoadTexture("Assets/7.png");
    Texture2D eight = LoadTexture("Assets/8.png");
    Texture2D nine = LoadTexture("Assets/9.png");
    Texture2D base = LoadTexture("Assets/base.png");
    Texture2D bifu = LoadTexture("Assets/bifu.png");
    Texture2D fruto = LoadTexture("Assets/fruto.png");
    Texture2D galho = LoadTexture("Assets/galho.png");
    Texture2D tronco = LoadTexture("Assets/tronco.png");
    Texture2D tronquino = LoadTexture("Assets/tronquinho.png");
    Texture2D CBE = LoadTexture("Assets/tile_0141.png");
    Texture2D CBM = LoadTexture("Assets/tile_0142.png");
    Texture2D CBD = LoadTexture("Assets/tile_0143.png");
    Texture2D contornoE = LoadTexture("Assets/tile_0021.png");
    Texture2D contornoD = LoadTexture("Assets/tile_0023.png");
    Texture2D espinhoE = LoadTexture("Assets/espinhoE.png");
    Texture2D espinhoD = LoadTexture("Assets/espinhoD.png");
    Texture2D espinhoB = LoadTexture("Assets/espinhoB.png");
 
    if(fase == 1){
        Texture2D nivel1[] = {
             cogumelo
        };
        BeginDrawing();//comeca a desenhar fase 1
            ClearBackground(BLACK);
            mostrarTextura1(nivel1, plat, recursos);
        EndDrawing();//final da fase 1
        
    }
    else if(fase == 2){
        Texture2D nivel2[] = {
            agua, contornoE, contornoD, chao2, CBE, CBM, CBD, chaoCeu, cordaEsq, cordaMeio, cordaDir, start, chao, esquerdo, meio, direito, espinhoE, espinhoD, espinhos, espinhoB, portal
        };
        BeginDrawing();//comeca fase 2
            ClearBackground(DARKGRAY);
            mostrarTextura2(nivel2, plat, recursos);
        EndDrawing();// termina fase 2
    }
    else if (fase == 3) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            final();
        EndDrawing();
    }
    else {
        
        Texture2D nivel[] = {
            agua, chao, direito, esquerdo, meio, meio, objeto, parede, parede, parede,chao2, chao1, espinhos, nuvem1, nuvem2, nuvem3, chaoCeu, arvore, portal, chave, start, cacto, right, cogumelo
        };
        BeginDrawing();//fase inicial 
            ClearBackground(BLACK);
            mostrarTextura(nivel, plat, recursos);
        EndDrawing();
        // final fase inicial
    }
    //Descarregar assets
    UnloadTexture(agua);     UnloadTexture(chao);     UnloadTexture(tronco);
    UnloadTexture(direito);  UnloadTexture(esquerdo); UnloadTexture(galho);
    UnloadTexture(meio);     UnloadTexture(cordaDir); UnloadTexture(fruto);
    UnloadTexture(objeto);   UnloadTexture(parede);   UnloadTexture(bifu);
    UnloadTexture(meio);     UnloadTexture(tronquino);UnloadTexture(base);
    UnloadTexture(chao2);    UnloadTexture(chao1);    UnloadTexture(base);
    UnloadTexture(espinhos); UnloadTexture(nuvem1);   UnloadTexture(one);
    UnloadTexture(nuvem2);   UnloadTexture(nuvem3);   UnloadTexture(two);
    UnloadTexture(chaoCeu);  UnloadTexture(arvore);   UnloadTexture(three);
    UnloadTexture(portal);   UnloadTexture(start);    UnloadTexture(four);
    UnloadTexture(cacto);    UnloadTexture(right);    UnloadTexture(five);
    UnloadTexture(six);      UnloadTexture(seven);    UnloadTexture(eight);
    UnloadTexture(nine);     UnloadTexture(cordaEsq); UnloadTexture(cordaMeio);
    UnloadTexture(CBE);      UnloadTexture(CBM);      UnloadTexture(CBD);
    UnloadTexture(contornoE);UnloadTexture(contornoD);
}