#include"datos_entrenamiento.h"
#include"datos_test.h"

//

//vectores promedio para cada tipo
float promedio[4] = {0, 0, 0, 0};
float promedio2[4] = {0, 0, 0, 0};
float promedio3[4] = {0, 0, 0, 0};

int on = 1;
float p = 0;
int filaoo = 0;
//-------limitacion de filas por tipo
//TIPO 1
int filao = 0;
int filaox = 0;
int filaf = 40;
//TIPO 2
int filao2 = 40;
int filaox2 = 40;
int filaf2 = 80;
//TIPO 3
int filao3 = 80;
int filaox3 = 80;
int filaf3 = 120;


float radio = 0.85;
float radiof = 0.935;
float radio2 = 0.2;
float radio3 = 0.2;

int col = 0;
int aux = 0;

float distancia = 0;
float distotal[40];
float distotal2[40];
float distotal3[40];

float dtnormal[40];
float dtnormal2[40];
float dtnormal3[40];
float dmaxima = 0;
float dmaxima2 = 0;
float dmaxima3 = 0;
float matrizreducida[40][5];



void setup() {
  Serial.begin(9600);

  //------------------------------------------------
  filaoo = filao;
  //>>>>>>>>PARA SACAR EL PROMEDIO DE LAS COLUMNAS
  //Serial.println("PROMEDIOS");
  // TIPO 1
  for (; col < 4; col++) {
    for (; filao < filaf; filao++) {
      p = p + entrenamiento[filao][col];
    }
    promedio[col] = p / (filao - filaoo);
    //Serial.print(promedio[col]);
    //Serial.print(' ');
    filao = filaoo;
    p = 0;
  }

  //TIPO 2
  col = 0;
  filaoo = filao2;
  for (; col < 4; col++) {
    for (; filao2 < filaf2; filao2++) {
      p = p + entrenamiento[filao2][col];
    }
    promedio2[col] = p / (filao2 - filaoo);
    // Serial.print(promedio2[col]);
    //Serial.print(' ');
    filao2 = filaoo;
    p = 0;
  }
  //Serial.println(' ');
  //TIPO 3
  col = 0;
  filaoo = filao3;
  for (; col < 4; col++) {
    for (; filao3 < filaf3; filao3++) {
      p = p + entrenamiento[filao3][col];
    }
    promedio3[col] = p / (filao3 - filaoo);
    //Serial.print(promedio3[col]);
    // Serial.print(' ');
    filao3 = filaoo;
    p = 0;
  }
  //Serial.println("DISTANCIAS");

  //>>>>>>>>>>>>>>>SACANDO LAS DISTANCIAS
  //TIPO 1
  filaoo = 0;
  for (filao = 0; filao < filaf; filao++) {
    for (col = 0; col < 4; col++) {
      distancia = distancia + pow(entrenamiento[filao][col] - promedio[col], 2);
    }
    distotal[filao - filaoo] = sqrt(distancia);
    //Serial.println(filao - filaoo);
    //Serial.println(distotal[filao - filaoo]);

    if (distotal[filao - filaoo] > dmaxima)
      dmaxima = distotal[filao - filaoo];
    col = 0;
    distancia = 0;
  }
  //TIPO 2
  filaoo = 40;
  distancia = 0;
  for (filao2 = 40; filao2 < filaf2; filao2++) {
    for (col = 0; col < 4; col++) {
      distancia = distancia + pow(entrenamiento[filao2][col] - promedio2[col], 2);
    }
    distotal2[filao2 - filaoo] = sqrt(distancia);
    //Serial.println(filao2 - filaoo);
    //Serial.println(distotal2[filao2 - filaoo]);

    if (distotal2[filao2 - filaoo] > dmaxima2)
      dmaxima2 = distotal2[filao2 - filaoo];
    col = 0;
    distancia = 0;
  }
  //TIPO 3
  filaoo = 80;
  distancia = 0;
  for (filao3 = 80; filao3 < filaf3; filao3++) {
    for (col = 0; col < 4; col++) {
      distancia = distancia + pow(entrenamiento[filao3][col] - promedio3[col], 2);
    }
    distotal3[filao3 - filaoo] = sqrt(distancia);
    //Serial.println(filao3 - filaoo);
    //Serial.println(distotal3[filao3 - filaoo]);

    if (distotal3[filao3 - filaoo] > dmaxima3)
      dmaxima3 = distotal3[filao3 - filaoo];
    col = 0;
    distancia = 0;
  }
  //>>>>>>>>>>>> NORMALIZANDO EL VECTOR DISTANCIAS
  //TIPO 1
  filaoo = 0;
  for (filao = 0; filao < filaf; filao++) {
    dtnormal[filao - filaoo] = distotal[filao - filaoo] / dmaxima;
  }
  filao = filaoo;

  for (; filao < filaf; filao++) {
    if (dtnormal[filao - filaoo] >= radio && dtnormal[filao - filaoo] <= radiof ) {
      for (; col < 5; col++) {
        matrizreducida[aux][col] = entrenamiento[filao][col];
      }
      aux++;
    }
    col = 0;
  }
  filaoo = 40;

  //TIPO 2

  for (filao2 = 40; filao2 < filaf2; filao2++) {
    dtnormal2[filao2 - filaoo] = distotal2[filao2 - filaoo] / dmaxima2;
  }


  for (filao2 = 40; filao2 < filaf2; filao2++) {
    if (dtnormal2[filao2 - filaoo] >= radio && dtnormal2[filao2 - filaoo] <= radiof) {
      for (; col < 5; col++) {
        matrizreducida[aux][col] = entrenamiento[filao2][col];
      }
      aux++;
    }
    col = 0;
  }
  filaoo = 80;

  //TIPO 3

  for (filao3 = 80; filao3 < filaf3; filao3++) {
    dtnormal3[filao3 - filaoo] = distotal3[filao3 - filaoo] / dmaxima3;
  }


  for (filao3 = 80; filao3 < filaf3; filao3++) {
    if (dtnormal3[filao3 - filaoo] >= radio && dtnormal3[filao3 - filaoo] <= radiof) {
      for (; col < 5; col++) {
        matrizreducida[aux][col] = entrenamiento[filao3][col];
      }
      aux++;
    }
    col = 0;
  }

  Serial.println(aux);
  float matriz[aux][5]; //MATRIZ REDUCIDA

  for (int i = 0; i < aux; i++)
    for (int j = 0; j < 5; j++)
      matriz[i][j] = matrizreducida[i][j];


  //PARA IMPRIMIR
  for (int i = 0; i < aux; i++) {
    for (; col < 5; col++) {
      Serial.print(matriz[i][col]);
      Serial.print(" ");
    }
    Serial.println(" ");
    col = 0;
  }

}


void loop() {

}
