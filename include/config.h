#ifndef Configuração
#define Configuração

typedef struct Player {
    Vector2 position;
    float speed;
    bool canJump;
    float width;
    float height;
} Player;

typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    int vert;
    Color color;
} EnvItem;

#define G 350
#define deslizar 50
#define PLAYER_JUMP_SPD 200.0f
#define PLAYER_HOR_SPD 200.0f

void mostrarTextura(Texture2D esquerdo, Texture2D direito, Texture2D agua, Texture2D chao, Texture2D meio, Texture2D mid, Texture2D objeto, Texture2D parede, Texture2D top);

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta);

#endif