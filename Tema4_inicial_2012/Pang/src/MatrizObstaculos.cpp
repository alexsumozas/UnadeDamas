#include "MatrizObstaculos.h"



MatrizObstaculos::MatrizObstaculos()
{
	for (int i= 0; i <C; i++) {
		for (int j = 0; j < F; j++) {

			matriz[i][j] = 0;
		}

}
	matriz[1][5] = 1;
	matriz[1][7] = 1;
	matriz[7][9] = 1;
	matriz[6][11] = 1;
}


MatrizObstaculos::~MatrizObstaculos()
{
}

void MatrizObstaculos::Inicializa( ) {
	vector2D aux(0, 0);
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < F; j++) {

			if (matriz[i][j] == 1) {
				aux.x = i;
				aux.y = j;
				obs[i][j] = new Obstaculo(0.3,aux);
			}
		}

	}

}



void MatrizObstaculos::Dibuja() {
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < F; j++) {

			if (obs[i][j] != 0) {
				obs[i][j]->Dibuja();
			}
		}
	}
}

void MatrizObstaculos::Mueve(float a[50],float b[50]) {

	float aux[50];
	float aux1[50];
	
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < F; j++) {
			if (obs[i][j] != 0) {
				for (int z = 0; z < 50; z++) {
					
					aux[z] = a[z] + i;
					aux1[z] = b[z] + j;
				}
				obs[i][j]->Mueve(aux,aux1);
			}
		}
	}


}