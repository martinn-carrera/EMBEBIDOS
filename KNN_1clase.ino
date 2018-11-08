#include"datos_entrenamiento.h"
#include"datos_test.h"
int col = 0;
int fil = 0;
float distancia = 0;
float num = 1000;
int c = 0;
int i = 3;
int f = 0;
int vec[50];
int op[3] = {0, 0, 0};

void setup() {
  Serial.begin(9600);

}

void loop() {
  if (f == 0) {
    for (; fil < 120; fil++) {
      distancia = sqrt( pow(matriz[fil][0] - prueba[19][0], 2) +
                        pow(matriz[fil][1] - prueba[19][1], 2) +
                        pow(matriz[fil][2] - prueba[19][2], 2) +
                        pow(matriz[fil][3] - prueba[19][3], 2));

      if (num > distancia) {
        num = distancia;
        vec[c] = matriz[fil][4];
        c++;
        Serial.println(matriz[fil][4]);
      }
    }
    f = 1;
  }
  if (f == 1) {
    Serial.println("distancias menores");
    for (; i > 0; i--) {
      Serial.println(vec[c - i]);
      if (vec[c - i] == 1)
        op[0]++;
      if (vec[c - i] == 2)
        op[1]++;
      if (vec[c - i] == 3)
        op[2]++;
    }

    f = 2;
  }
  if (f == 2) {
    c = op[0];
    for (int j = 0; j < 2; j++) {
      if (op[0] < op[j + 1])
        c = op[j + 1];

    }
    for (int j = 0; j < 3; j++) {
      if (c == op[j]) {
        if (j == 0)
          Serial.println("iris_setosa");
        if (j == 1)
          Serial.println("iris_versicolor");
        if (j == 2)
          Serial.println("iris_virginica");
      }
    }
    f = 3;
  }

}
