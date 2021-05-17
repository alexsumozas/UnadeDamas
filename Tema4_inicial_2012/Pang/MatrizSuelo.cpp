#include "src\MatrizSuelo.h"
#include <cstdlib>
#include <time.h>
#define anchura 1;
#define altura 1;


MatrizSuelo::MatrizSuelo()
{
	srand(time_t(NULL));
	contador = 0;

	for (int i = 0; i < F; i++)
	{

		for (int j = 0; j < C; j++) {
	
			spunt[i][j] =NULL;
			//spnormal[i][j] = NULL;


		}
	}

}


MatrizSuelo::~MatrizSuelo()
{
}

vector2D MatrizSuelo::matrizInicializa() {

	

	for (int i = 0; i < F; i++)
	{

		for (int j = 0; j < C; j++) {
			vector2D c;
			c.x = (float)(i-1 )* anchura  ;
			c.y = (float)(j+1 )*anchura ;
			
			if (matriz[i][j] == 1)
			{
				
				spunt[i][j] = new SueloDecor(c);
			}
			if (matriz[i][j] == 2) {
				spnormal[i][j] = new SueloNormal(c);

			}
			if (matriz[i][j] == 4) {
				spmeta[i][j] = new SueloMeta(c);

			}
			if (matriz[i][j] == 3) {
				scasa = new SueloCasa(c);
				
			}



		}
	}
	return scasa->centro;
}

void MatrizSuelo::Dibuja() {

	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			if ( spunt[i][j] != 0) {

				spunt[i][j]->Dibuja();
			}
			if ( spnormal[i][j]!=0) {

				spnormal[i][j]->Dibuja();
			}
			if (spmeta[i][j] != NULL) {

				spmeta[i][j]->Dibuja();
			}
		}

	}
	scasa->Dibuja();
}