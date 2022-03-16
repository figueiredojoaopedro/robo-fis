// esse script foi feito para retonar um array com a trajetória do robo até a bola.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pos.h"
// aceleracao do robo é igual a 2.8 m/sˆ2
#define acceleration 2.8 
// velocidade max do robo é igual ao 0.92 m/s
#define velocityMax 0.92
// pos x e y da bola no final da trajetoria
#define pos_ball_x 9.000
#define pos_ball_y 5.300

// retorna o array da posicao x
float posX(float x_initial){
    float pos_robo_x = x_initial;
    float velocity = 0;
    float velocity_x_max = velocityMax * cos(delta);
    if(x_initial != pos_ball_x){
        while (x_initial != pos_ball_x){
        }
    }
}
// retorna o array da posicao y
float posY(float y_initial){
    float pos_robo_y = y_initial;
    float velocity = 0;
}