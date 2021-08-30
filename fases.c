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
        for(j=340; j<580; j+=20){
            if(j!=340) DrawTexture(nivel[11], i, j, WHITE);
            else DrawTexture(nivel[10], i, j, WHITE);
        }
    }
    DrawText("Pule pra cá", 380, 380, 20, DARKBLUE);
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
            for(j=0; j<340; j+=20){
                DrawTexture(nivel[17], i, j, WHITE);
            }
        }
    }

    DrawTexture(nivel[18], 710, 520, WHITE);
}

void mostrarTextura1(Texture2D *nivel1, Plataforma *plat, Feature *recursos) {
    int i, j;
    
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
                if (recursos[0].bloqueado) DrawTexture(nivel1[15], i, j, WHITE);
            }
            else
                DrawTexture(nivel1[12], i, j, WHITE);
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
                DrawTexture(nivel1[10], i, j, WHITE);
            else
                DrawTexture(nivel1[9], i, j, WHITE);
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
            if (recursos[2].bloqueado)
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
    if (recursos[0].bloqueado) DrawTexture(nivel1[19], 30, 40, WHITE); 
    if (recursos[1].bloqueado) DrawTexture(nivel1[19], 40, 350, WHITE);
    if (recursos[2].bloqueado) DrawTexture(nivel1[19], 280, 530, WHITE);

    for (i = 360; i < 381; i+=20) {
        for (j = 440; j < 560; j+=20) 
            if (recursos[1].bloqueado) DrawTexture(nivel1[12], i, j, WHITE);
    }

    DrawTexture(nivel1[6], 751, 152, WHITE);
    DrawTexture(nivel1[6], 731, 152, WHITE);

}

void mostrarTextura2(Texture2D *nivel2, Plataforma *plat, Feature *recursos) {
    int i, j;
    // agua[0], contornoE[1], contornoD[2], chao2[3], CBE[4], CBM[5], CBD[6]
    for (i = 0; i < 40; i++) DrawTexture(nivel2[0], i*20, 580, WHITE);
    DrawTexture(nivel2[1], 80, 560, WHITE);
    for (i = 100; i < 180; i+= 20) DrawTexture(nivel2[3], i, 560, WHITE);
    DrawTexture(nivel2[2], 180, 560, WHITE);
    DrawTexture(nivel2[4], 80, 580, WHITE);
    for (i = 100; i < 180; i+= 20) DrawTexture(nivel2[5], i, 580, WHITE);
    DrawTexture(nivel2[6], 180, 580, WHITE);
    
    //chaoCeu[7], cordaEsq[8], cordaMeio[9], cordaDir[10], bandeira[11]
    for (i = 200; i < 400; i+= 20) {
        for (j = 520; j < 560; j+= 20)
            DrawTexture(nivel2[7], i, j, WHITE);
    }
    for (i = 80; i < 360; i+= 20) {
        for (j = 440; j < 480; j+= 20)
            DrawTexture(nivel2[7], i, j, WHITE);
    }
    
    for (i = 200; i < 580; i+= 20) DrawTexture(nivel2[9], i, 560, WHITE);
    DrawTexture(nivel2[8], 200, 560, WHITE);
    DrawTexture(nivel2[10], 580, 560, WHITE);
    DrawTexture(nivel2[11], 80, 540, WHITE);

    //caixote[12]
    for (i = 600; i < 760; i+= 20) {
        for (j = 560; j < 600; j+= 20) 
            DrawTexture(nivel2[12], i, j, WHITE);
    } 

    for (i = 720; i < 760; i+= 20) {
        for (j = 320; j < 560; j+= 20) 
            DrawTexture(nivel2[12], i, j, WHITE);
    } 

    if (recursos[0].bloqueado) {
        for (i = 760; i < 801; i+= 20) 
            for (j = 320; j < 360; j+=20)
                DrawTexture(nivel2[7], i, j, WHITE);
    }
    // esquerdo[13], meio[14], direito[15], espinhoE[16], espinhoD[17], espinhos[18], espinhoB[19]
    DrawTexture(nivel2[13], 160, 120, WHITE);
    for (i = 180; i < 660; i+= 20) DrawTexture(nivel2[14], i, 120, WHITE);
    DrawTexture(nivel2[15], 660, 120, WHITE);
    DrawTexture(nivel2[4], 160, 140, WHITE);
    for (i = 180; i < 660; i+= 20) DrawTexture(nivel2[5], i, 140, WHITE);
    
    for (i = 560; i < 600; i += 20) {
        DrawTexture(nivel2[18], i, 100, WHITE);
    }
    for (i = 580; i < 600; i+=20) {
        for (j = 240; j < 500; j += 20) {
            DrawTexture(nivel2[16], i, j, WHITE);
        }
    }

    for (i = 640; i < 660; i+=20) {
        for (j = 160; j < 520; j += 20) {
            DrawTexture(nivel2[17], i, j, WHITE);
        }
    }

    //parede[21], cogumelbase[22], chaocogumeloesquerda[23], chaocogumeloireita[24], cogumelovermelho[25], chaoCogumelomeio[47]
    DrawTexture(nivel2[26], 400, 200, WHITE);
    for (i = 400 ; i < 420 ; i += 20)
        for (j = 220 ; j < 480 ; j+=20)
            DrawTexture(nivel2[21], i, j, WHITE);

    DrawTexture(nivel2[22],400, 480, WHITE);
    DrawTexture(nivel2[23],400, 500, WHITE);
    DrawTexture(nivel2[47],420, 500, WHITE);
    DrawTexture(nivel2[24],440, 500, WHITE);
    DrawTexture(nivel2[25],420, 480, WHITE);
    //coguelomeio[26] cogumeloesquerda[27], cogumelodireita[28], base[29], tronco[30], troquinho[31]
    //arvore[32], base[33] bifu[34], eight[35], seven[36], nine[37], five[38]
    DrawTexture(nivel2[27],380, 200, WHITE);
    DrawTexture(nivel2[26],400, 200, WHITE);
    DrawTexture(nivel2[28],420, 200, WHITE);

    for (i = 540 ; i < 560 ; i += 20)
        for (j = 240 ; j < 480 ; j+=20)
            if (j%80 == 0)
                DrawTexture(nivel2[30], i, j, WHITE);
            else if (j%40 == 0)
                DrawTexture(nivel2[31], i, j, WHITE);
            else
                DrawTexture(nivel2[32], i, j, WHITE);

    for (i = 560 ; i < 580 ; i += 20)
        for (j = 240 ; j < 500 ; j+=20)
           DrawTexture(nivel2[12], i, j, WHITE);
    
    DrawTexture(nivel2[33], 540, 480, WHITE);

    DrawTexture(nivel2[2], 560, 500, WHITE);
    DrawTexture(nivel2[3], 540, 500, WHITE);
    DrawTexture(nivel2[5], 540, 520, WHITE);
    DrawTexture(nivel2[3], 520, 500, WHITE);
    DrawTexture(nivel2[5], 520, 520, WHITE);
    DrawTexture(nivel2[1], 500, 500, WHITE);
    DrawTexture(nivel2[6], 560, 520, WHITE);
    DrawTexture(nivel2[4], 500, 520, WHITE);

    DrawTexture(nivel2[36], 500, 220, WHITE);
    DrawTexture(nivel2[35], 520, 220, WHITE);
    DrawTexture(nivel2[35], 560, 220, WHITE);
    DrawTexture(nivel2[34], 540, 220, WHITE);
    DrawTexture(nivel2[37], 580, 220, WHITE);

    //one[39], two[40], three[41], four[42], six[43], meiota[44], baixeta[45], direitota[46],chaoCogumelomeio[47], olaf[48]
    for (i = 520 ; i < 580 ; i += 20)
        for (j = 180 ; j < 220 ; j+=20)
            DrawTexture(nivel2[38], i, j, WHITE);

    DrawTexture(nivel2[39], 500, 160, WHITE);
    DrawTexture(nivel2[41], 580, 160, WHITE);

    for (i = 520, j = 160 ; i < 580 ; i += 20)
        DrawTexture(nivel2[40], i, j, WHITE);
    
    for (i = 500 ; i < 520 ; i += 20)
        for (j = 180 ; j < 220 ; j+=20)
            DrawTexture(nivel2[42], i, j, WHITE);

    for (i = 580 ; i < 600 ; i += 20)
        for (j = 180 ; j < 220 ; j+=20)
            DrawTexture(nivel2[43], i, j, WHITE);
    
    for (i = 660 ; i < 680 ; i += 20)
        for (j = 160 ; j < 500 ; j+=20)
            DrawTexture(nivel2[44], i, j, WHITE);
    
    DrawTexture(nivel2[45], 660, 500, WHITE);
    DrawTexture(nivel2[46], 660, 140, WHITE);

    DrawTexture(nivel2[18], 210, 30, WHITE);
    DrawTexture(nivel2[19], 210, 70, WHITE);
    DrawTexture(nivel2[17], 190, 50, WHITE);
    DrawTexture(nivel2[16], 230, 50, WHITE);
    DrawTexture(nivel2[12], 210, 50, WHITE);

    for (i = 450 ; i < 510 ; i += 20) DrawTexture(nivel2[12], i, 50, WHITE);
    for (i = 450 ; i < 510 ; i += 20) DrawTexture(nivel2[18], i, 30, WHITE);
    for (i = 450 ; i < 510 ; i += 20) DrawTexture(nivel2[19], i, 70, WHITE);
    DrawTexture(nivel2[16], 510, 50, WHITE);
    DrawTexture(nivel2[17], 430, 50, WHITE);

    //olaf[48], nevinha[49], esquerdota[50]
    DrawTexture(nivel2[48], 220, 102, WHITE);
    DrawTexture(nivel2[48], 500, 102, WHITE);
    DrawTexture(nivel2[49], 180, 100, WHITE);
    DrawTexture(nivel2[49], 640, 100, WHITE);
    DrawTexture(nivel2[49], 360, 100, WHITE);

    DrawTexture(nivel2[13], 80, 160, WHITE);
    DrawTexture(nivel2[15], 100, 160, WHITE);

    for (j = 180 ; j < 300 ; j += 20) DrawTexture(nivel2[46], 100, j, WHITE);
    for (j = 180 ; j < 300 ; j += 20) DrawTexture(nivel2[50], 80, j, WHITE);
    DrawTexture(nivel2[4], 80, 300, WHITE);
    DrawTexture(nivel2[6], 100, 300, WHITE);
    DrawTexture(nivel2[48], 90, 142, WHITE);

    DrawTexture(nivel2[1], 0, 280, WHITE);
    DrawTexture(nivel2[2], 20, 280, WHITE);
    DrawTexture(nivel2[4], 0, 300, WHITE);
    DrawTexture(nivel2[6], 20, 300, WHITE);

    if (recursos[0].bloqueado) DrawTexture(nivel2[20], 10, 90, WHITE);
    if (!recursos[0].bloqueado) {
        DrawTexture(nivel2[52], 5, 245, WHITE);
        DrawTexture(nivel2[53], 760, 400, WHITE);
    }

    if (recursos[0].bloqueado) {
        for (i = 0; i < 80; i+= 20) 
            for (j = 200; j < 201; j+=20)
                DrawTexture(nivel2[7], i, j, WHITE);
    }

    DrawTexture(nivel2[51], 770, 480, WHITE);
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
    Texture2D porta = LoadTexture("Assets/porta.png");
    Texture2D agua1 = LoadTexture("Assets/agua1.png");
    Texture2D core = LoadTexture("Assets/core.png");
    Texture2D azulejo = LoadTexture("Assets/azulejo.png");
    Texture2D cogumelodireito = LoadTexture("Assets/cogumelodireito.png");
    Texture2D cogumeloesquerda = LoadTexture("Assets/cogumeloesquerda.png");
    Texture2D cogumelodireita = LoadTexture("Assets/cogumelodireita.png");
    Texture2D cogumelobase = LoadTexture("Assets/cogumelobase.png");
    Texture2D cogumelovermelho = LoadTexture("Assets/cogumelovermelho.png");
    Texture2D chaoCogumelocompleto = LoadTexture("Assets/chaoCogumelocompleto.png");
    Texture2D chaoCogumeloesquerda = LoadTexture("Assets/chaoCogumeloesquerda.png");
    Texture2D chaoCogumelodireita = LoadTexture("Assets/chaoCogumelodireita.png");
    Texture2D chaoCogumelomeio = LoadTexture("Assets/chaoCogumelomeio.png");
    Texture2D cogumelomeio = LoadTexture("Assets/cogumelomeio.png");
    Texture2D meiota = LoadTexture("Assets/meiota.png");
    Texture2D baixeta = LoadTexture("Assets/baixeta.png");
    Texture2D direitota = LoadTexture("Assets/direitota.png");
    Texture2D olaf = LoadTexture("Assets/olaf.png");
    Texture2D nevinha = LoadTexture("Assets/nevinha.png");
    Texture2D esquerdota = LoadTexture("Assets/esquerdota.png");
    Texture2D chaoCompleto1 = LoadTexture("Assets/tile_0000.png");
    Texture2D in = LoadTexture("Assets/sprite_22.png");
    Texture2D out = LoadTexture("Assets/sprite_40.png");
 
    if(fase == 1){
        Texture2D nivel1[] = {
              agua, chao, direito, esquerdo, meio, meio, objeto, parede, parede, chao1, chao2, chao2, chaoCeu, agua1, core, porta, azulejo, cogumelo, CBE, chave
        };
        BeginDrawing();//comeca a desenhar fase 1
            ClearBackground(BLACK);
            mostrarTextura1(nivel1, plat, recursos);
        EndDrawing();//final da fase 1
        
    }
    else if(fase == 2){
         Texture2D nivel2[] = {
            agua, contornoE, contornoD, chao2, CBE,
            CBM, CBD, chaoCeu, cordaEsq, cordaMeio, 
            cordaDir, start, chao, esquerdo, meio, 
            direito, espinhoE, espinhoD, espinhos, espinhoB,
            chave, parede, cogumelobase, chaoCogumeloesquerda, chaoCogumelodireita,
            cogumelovermelho, cogumelomeio, cogumeloesquerda, cogumelodireita, base,
            tronco, tronquino, arvore, base, bifu, 
            eight, seven, nine, five, one,
            two, three, four, six, meiota,
            baixeta, direitota, chaoCogumelomeio, olaf, nevinha,
            esquerdota, portal, in, out
        };
        BeginDrawing();//comeca fase 2
            ClearBackground(DARKGRAY);
            mostrarTextura2(nivel2, plat, recursos);
        EndDrawing();// termina fase 2
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
    UnloadTexture(contornoE);UnloadTexture(contornoD);UnloadTexture(core);
    UnloadTexture(porta);    UnloadTexture(agua1);    UnloadTexture(azulejo);
    UnloadTexture(espinhoB); UnloadTexture(espinhoD); UnloadTexture(espinhoE);
    UnloadTexture(meiota);   UnloadTexture(baixeta);  UnloadTexture(direitota);
    UnloadTexture(olaf);     UnloadTexture(nevinha);  UnloadTexture(cogumelomeio);
    
    UnloadTexture(esquerdota);          UnloadTexture(cogumelobase);              
    UnloadTexture(cogumelovermelho);    UnloadTexture(chaoCogumelocompleto);  
    UnloadTexture(chaoCogumelodireita); UnloadTexture(chaoCogumeloesquerda);    
    UnloadTexture(chaoCogumelomeio);    UnloadTexture(chaoCompleto1); 
    UnloadTexture(cogumelodireito);     UnloadTexture(cogumeloesquerda);
    UnloadTexture(cogumelodireita);     UnloadTexture(chave);
    UnloadTexture(cogumelo);      UnloadTexture(in);      UnloadTexture(out);
}