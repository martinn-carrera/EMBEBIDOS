#include"datos_entrenamiento.h"

float promedio[4] = {0, 0, 0, 0};
int on = 1;
float p = 0;
int filao2 = 0;

int filao = 80;
int filaf = 120;
float radio = 0.2;

int col = 0;
int aux = 0;

float distancia = 0;
float distotal[40];
float dtnormal[40];
float dmaxima = 0;
float matrizreducida[40][5];



void setup() {
  Serial.begin(9600);
}

void loop() {
  if (on == 1) {
    filao2 = filao;
    //PARA SACAR EL PROMEDIO DE LAS COLUMNAS
    for (; col < 4; col++) {
      for (; filao < filaf; filao++) {
        p = p + matriz[filao][col];
      }
      promedio[col] = p / (filao - filao2);

      filao = filao2;
      p = 0;
    }
    filao = filao2;
    col = 0;

    //SACANDO LAS DISTANCIAS
    for (; filao < filaf; filao++) {
      for (; col < 4; col++) {
        distancia = distancia + pow(matriz[filao][col] - promedio[col], 2);
      }
      distotal[filao - filao2] = sqrt(distancia);

      if (distotal[filao - filao2] > dmaxima)
        dmaxima = distotal[filao - filao2];
      col = 0;
      distancia = 0;
    }
    filao = filao2;
    //NORMALIZANDO LAS DISTANCIAS
    for (; filao < filaf; filao++) {
      dtnormal[filao - filao2] = distotal[filao - filao2] / dmaxima;
    }
    filao = filao2;

    for (; filao < filaf; filao++) {
      if (dtnormal[filao - filao2] < radio) {
        for (; col < 5; col++) {
          matrizreducida[aux][col] = matriz[filao][col];
        }
        aux++;
      }
      col = 0;
    }
    filao = filao2;


    //PARA IMPRIMIR
    for (int i = 0; i < aux; i++) {
      for (; col < 5; col++) {
        Serial.print(matrizreducida[i][col]);
        Serial.print(" ");
      }
      Serial.println(" ");
      col = 0;
    }
  }
  on = 2;
}
