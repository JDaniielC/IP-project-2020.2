#include "raylib.h"
#include "config.h"

void mostrarTextura(Texture2D esquerdo, Texture2D direito, Texture2D agua, Texture2D chao, Texture2D meio, Texture2D mid, Texture2D objeto, Texture2D parede, Texture2D top) {
    int i, k;
    Rectangle retangulo[] = {
        { 0, 0, 800, 10 },
        { 0, 0, 10, 600 },
        { 798, 0, 10, 600 },
        { 0, 598, 800, 10 },
        {60, 580, 100, 20},
        {180, 520, 100, 20},
        {300, 440, 100, 20},
        {700, 300, 100, 20},
        {500, 400, 100, 20},
        {300, 200, 100, 20},
        {500, 200, 80, 20},
        {180, 280, 40, 20},
        {460, 300, 20, 100},
        {150, 230, 20, 60},
    };
    
    DrawTextureRec(mid, retangulo[0], (Vector2){retangulo[0].x, retangulo[0].y}, WHITE);
    DrawTextureRec(parede, retangulo[1], (Vector2){retangulo[1].x, retangulo[1].y}, WHITE);
    DrawTextureRec(mid, retangulo[3], (Vector2){retangulo[3].x, retangulo[3].y}, WHITE);
    DrawTextureRec(parede, retangulo[2], (Vector2){retangulo[2].x, retangulo[2].y}, WHITE);

    for (k = 4; k < 12; k++) {
        DrawTexture(esquerdo, retangulo[k].x, retangulo[k].y, WHITE);
        for (i = retangulo[k].x+20; i <= retangulo[k].x + retangulo[k].width - 40; i+=20){
            DrawTexture(mid, i, retangulo[k].y, WHITE);
        }
        DrawTexture(direito, retangulo[k].x + retangulo[k].width - 20, retangulo[k].y, WHITE);
    }

    for (k = 12; k < 14; k++) {
        DrawTexture(top, retangulo[k].x, retangulo[k].y, WHITE);
        for (i = retangulo[k].y+20; i < retangulo[k].y + retangulo[k].height; i+=20){
            DrawTexture(meio, retangulo[k].x, i, WHITE);
        }
        DrawTexture(chao, retangulo[k].x, retangulo[k].y + retangulo[k].height, WHITE);
    }

}