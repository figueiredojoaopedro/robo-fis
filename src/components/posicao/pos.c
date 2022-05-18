
// esse script foi feito para retonar um array com a trajetória do robo até a bola.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pos.h"
// aceleracao do robo é igual a 2.8 m/sˆ2
#define aceleracao 2.8
// velocidade max do robo é igual ao 2.8 m/s
#define velocidadeMax 2.8
// pos x e y da bola no final da trajetoria

// retorna o array da posicao x e y
float pos(float roboX[], float roboY[], float cos[], float sin[], float vetorBolaY[], float vetorBolaX[], float vetorTempoBola[]) {

  // algumas variaveis importantes
  float veloRoboX[1001], veloRoboY[1001], veloRobo[1001], veloBolaX[1001], veloBolaY[1001], dist2[1001];
  float dist = 0;
  int i = 0;
  // aumento da velocidade até a velocidade max
  for(i = 0; i < 1002; i++){
    veloRobo[i] = aceleracao * vetorTempoBola[i];  
    if (veloRobo[i] >= velocidadeMax){
      veloRobo[i] = velocidadeMax;
    }                 
  }
  for(i=0; i<1002; i++){
    dist2[i] = ((vetorBolaX[i] - roboX[i]) * (vetorBolaX[i] - roboX[i])) + ((vetorBolaY[i] - roboY[i]) * (vetorBolaY[i] - roboY[i]));//distancia entre os dois pontos, entre a bola e o robo
          
    cos[i] = (vetorBolaX[i] - roboX[i]) / sqrt(dist2[i]); //acha o cosseno
    sin[i] = (vetorBolaY[i] - roboY[i]) / sqrt(dist2[i]); //acha o seno
    roboX[i+1] = roboX[i] + (cos[i] * 0.04); //vai aumentando a posicao do robo em X
    roboY[i+1] = roboY[i] + (sin[i] * 0.05); //vai aumentando a posicao do robo em Y

    if (roboX[i] >= vetorBolaX[i] - 0.1 && roboX[i] <= vetorBolaX[i] + 0.1 && roboY[i] >= vetorBolaY[i] - 0.1 && roboY[i] <= vetorBolaY[i] + 0.1){ // o raio de interceptação do robo é 0.075 metros + 0.025 metros de raio da bola

    // print de quando o robo encontrar a bola
      printf ("Autobots!!! A bola foi encontrada com sucesso!!\n");
      printf("Robo (X,Y): (%.3f, %.3f)m | Velocidade: %.3f m/s\n", roboX[i], roboY[i], veloRobo[i]);
      printf("Bola (X,Y): (%.3f, %.3f)m\n", vetorBolaX[i], vetorBolaY[i]);
      printf("Tempo: %.3f s\n", vetorTempoBola[i]);
      break;
    }
    else{
    // se o robo ainda n encontrou a bola, ele vai printar a sua posicao acada 0.02s
      printf("ROBO(X,Y): (%.3f, %.3f)m | Tempo: %.3f s | Velocidade: %.3f m/s\n", roboX[i], roboY[i], vetorTempoBola[i], veloRobo[i]);
    printf("BOLA(X,Y): (%.3f, %.3f)m\n\n", vetorBolaX[i], vetorBolaY[i]);         
    } 
  } 
  return 0.0;
}
