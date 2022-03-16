#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// modules:
#include "./components/position/pos.h"


int main (void) {
    float pos_x, pos_y;

    // entrada da posicao x e y do robo no plano 
    printf("Digite a posicao X do robo:\n");
    scanf("%f", &pos_x);
    
    // detalhe, pos x tem que ser no max 9 e n menor que 0
    while (pos_x > 9 || pos_x < 0){
        printf("!!!!!!!!!!!\nPosição do robo inválida\n");
        printf("Digite a posicao X do robo:\n");
        scanf("%f", &pos_x);
    }

    // mesma coisa com o y
    printf("Digite a posicao Y do robo:\n");
    scanf("%f", &pos_y);
    while (pos_y > 6 || pos_y < 0){
        printf("!!!!!!!!!!!\nPosição do robo inválida\n");
        printf("Digite a posicao Y do robo:\n");
        scanf("%f", &pos_y);
    }

    printf("Posicao X: %f\n Posicao Y: %f", posX(pos_x), posY(pos_y));

    return 0;
}
