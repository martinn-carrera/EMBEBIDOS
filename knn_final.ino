#include"datos_entrenamiento.h"
#include"datos_test.h"
int col = 0;
int fil = 0;
float distancia = 0;
float n1 = 0;
float n2 = 0;
int c = 0;
int nvecinos = 3;
int f = 0;
float mat[120][2];
float vec[3];
float xx[3]={1,2,3};

void setup() {
  Serial.begin(9600);

}

void loop() {
  if (f == 0) {
    for (; fil < 120; fil++) {
      distancia = sqrt( pow(matriz[fil][0] - prueba[20][0], 2) +
                        pow(matriz[fil][1] - prueba[20][1], 2) +
                        pow(matriz[fil][2] - prueba[20][2], 2) +
                        pow(matriz[fil][3] - prueba[20][3], 2));

      mat[fil][0] = distancia;
      mat[fil][1] = matriz[fil][4];
    }
    f = 1;

  }
  if (f == 1) {
    for (int j = 0; j < 120; j++) {
      Serial. print(mat[j][0]);
      Serial. print("..");
      Serial. println(mat[j][1]);
    }
    f = 2;
  }

  if (f == 2) {
    ordenar();
    Serial. println("-------------");
    for (int j = 0; j < 120; j++) {
      Serial. print(mat[j][0]);
      Serial. print("..");
      Serial. println(mat[j][1]);
    }
    vecino();
    f = 3;
  }

}

void ordenar() {
  for (int i = 0; i < 120; i++) {
    for (int x = i + 1 ; x <= 119; x++) {
      if (mat[i][0] > mat[x][0]) {
        n1 = mat[i][0];
        n2 = mat[i][1];
        mat[i][0] = mat[x][0];
        mat[i][1] = mat[x][1];
        mat[x][0] = n1;
        mat[x][1] = n2;
      }
    }
  }
}

void vecino() {

  int op[nvecinos];
  Serial. println("-------------");
  
  for (int i = 0; i < 3; i++) {
    if (mat[i][1] == 1)
      op[0]++;
    if (mat[i][1] == 2)
      op[1]++;
    if (mat[i][1] == 3)
      op[2]++;
  }
  Serial. println(op[0]);
  Serial. println(op[1]);
  Serial. println(op[2]);

  for (int j = 0; j < 3; j++) {
    if (op[j] > 2) {
      if (mat[j][1] == xx[0])
        Serial.println("iris_setosa");
      if (mat[j][1] == xx[1])
        Serial.println("iris_versicolor");
      if (mat[j][1] == xx[2])
        Serial.println("iris_virginica");
    }
  }


}
