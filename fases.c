#include "raylib.h"
#include "config.h"

void mostrarTextura(Texture2D *nivel, Plataforma *plat, Feature *recursos) {
    int i, k;
    
    DrawTextureRec(nivel[5], plat[0].rect, (Vector2){plat[0].rect.x, plat[0].rect.y}, WHITE);
    DrawTextureRec(nivel[7], plat[1].rect, (Vector2){plat[1].rect.x, plat[1].rect.y}, WHITE);
    DrawTextureRec(nivel[5], plat[3].rect, (Vector2){plat[3].rect.x, plat[3].rect.y}, WHITE);
    DrawTextureRec(nivel[7], plat[2].rect, (Vector2){plat[2].rect.x, plat[2].rect.y}, WHITE);

    for (k = 4; k < 12; k++) {
        DrawTexture(nivel[3], plat[k].rect.x, plat[k].rect.y, WHITE);
        for (i = plat[k].rect.x+18; i <= plat[k].rect.x + plat[k].rect.width - 20; i+=18){
            DrawTexture(nivel[5], i, plat[k].rect.y, WHITE);
        }
        DrawTexture(nivel[2], plat[k].rect.x + plat[k].rect.width - 10, plat[k].rect.y, WHITE);
    }

    for (k = 12; k < 14; k++) {
        DrawTexture(nivel[8], plat[k].rect.x, plat[k].rect.y, WHITE);
        for (i = plat[k].rect.y+18; i < plat[k].rect.y + plat[k].rect.height; i+=18){
            DrawTexture(nivel[4], plat[k].rect.x, i, WHITE);
        }
        DrawTexture(nivel[1], plat[k].rect.x, plat[k].rect.y + plat[k].rect.height, WHITE);
    }

}

void mostrarTextura1(Texture2D *nivel1, Plataforma *plat, Feature *recursos) {

}

void mostrarTextura2(Texture2D *nivel2, Plataforma *plat, Feature *recursos) {

}

void niveis(int fase, Plataforma *plat, Feature *recursos){
    //Carregar assets
    Texture2D agua = LoadTexture("Assets/agua.png");
    Texture2D chao = LoadTexture("Assets/chao.png");
    Texture2D direito = LoadTexture("Assets/direito.png");
    Texture2D esquerdo = LoadTexture("Assets/esquerdo.png");
    Texture2D meio = LoadTexture("Assets/meio.png");
    Texture2D mid = LoadTexture("Assets/mid.png");
    Texture2D objeto = LoadTexture("Assets/objeto.png");
    Texture2D parede = LoadTexture("Assets/parede.png");
    Texture2D top = LoadTexture("Assets/top.png");
  
    if(fase == 1){
        Texture2D nivel1[] = {
            agua, chao, direito, esquerdo, meio, mid, objeto, parede, top
        };
        BeginDrawing();//comeca a desenhar fase 1
            ClearBackground(RAYWHITE);
            mostrarTextura1(nivel1, plat, recursos);
        EndDrawing();//final da fase 1
        
    }
    else if(fase == 2){
        Texture2D nivel2[] = {
            agua, chao, direito, esquerdo, meio, mid, objeto, parede, top
        };
        BeginDrawing();//comeca fase 2
            ClearBackground(RAYWHITE);
            mostrarTextura2(nivel2, plat, recursos);
        EndDrawing();// termina fase 2
    }
    else {
    // agua[0], chao[1], direito[2], esquerdo[3], meio[4], mid[5], objeto[6], parede[7], top[8]
        Texture2D nivel[] = {
            agua, chao, direito, esquerdo, meio, mid, objeto, parede, top
        };
        BeginDrawing();//fase inicial 
            ClearBackground(RAYWHITE);
            mostrarTextura(nivel, plat, recursos);
        EndDrawing();// final fase inicial||| ao sair daqui tem q ir direto para a fase 1 especificamente
    }
    //Descarregar assets
    UnloadTexture(agua);
    UnloadTexture(chao);
    UnloadTexture(direito);
    UnloadTexture(esquerdo);
    UnloadTexture(meio);
    UnloadTexture(mid);
    UnloadTexture(objeto);
    UnloadTexture(parede);
    UnloadTexture(top);
}