#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// modules:
#include "./components/posicao/pos.h"


int main(void){
  // leitura do tempo no arquivo t.txt
  FILE *tempo;
	float vetorTempoBola[1001];
	int i=0;
	tempo=fopen("./components/leituradeArquivos/t.txt","r");// abre o arquivo do tempo
  // ler o arquivo t.txt e colocar os valores float em um vetor de 1001 posições
  while(!feof(tempo)){
    fscanf(tempo,"%f",&vetorTempoBola[i]);
    i++;
  }
  fclose(tempo);
  i = 0; // zerar a variavel i para iniciar o outro laco
	
  // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=--==-=-

  // leitura bola x
  FILE *bolaX;
	float vetorBolaX[1001];
	bolaX=fopen("./components/leituradeArquivos/x.txt","r");// abre o arquivo da pos x
  // ler o arquivo x.txt e colocar os valores float em um vetor de 1001 posições
  while(!feof(bolaX)){
    fscanf(bolaX,"%f",&vetorBolaX[i]);
    i++;
  }
  fclose(bolaX);
  i = 0; // zerar a variavel i para iniciar o outro laco

  // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=--==-=-

  // leitura bola y
  FILE *bolaY;
	float vetorBolaY[1001];
	bolaY=fopen("./components/leituradeArquivos/y.txt","r");// abre o arquivo da pos y
  // ler o arquivo y.txt e colocar os valores float em um vetor de 1001 posições
  while(!feof(bolaY)){
    fscanf(bolaY,"%f",&vetorBolaY[i]);
    i++;
  }
  fclose(bolaY);
  i = 0; // zerar a variavel i para iniciar o outro laco

  // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  
  float roboX[1001], roboY[1001]; // posicao inicial do robo
  float cos[1001], sin[1001];
  // entrada da posicao x e y do robo no plano
  printf("Digite a posicao X do robo:\n");
  scanf("%f", &roboX[0]);

  // detalhe, pos x tem que ser no max 9 e n menor que 0
  while (roboX[0] > 9 || roboX[0] < 0){
    printf("!!!!!!!!!!!\nPosição do robo inválida\n");
    printf("Digite a posicao X do robo:\n");
    scanf("%f", &roboX[0]);
  }

  // mesma coisa com o y
  printf("Digite a posicao Y do robo:\n");
  scanf("%f", &roboY[0]);
  while (roboY[0] > 6 || roboY[0] < 0){
    printf("!!!!!!!!!!!\nPosição do robo inválida\n");
    printf("Digite a posicao Y do robo:\n");
    scanf("%f", &roboY[0]);
  }


  // chamando a funcao posicao
  pos(roboX, roboY, cos, sin, vetorBolaY, vetorBolaX, vetorTempoBola);
  // informacoes cinematicas importantes
  
  return 0;
}
