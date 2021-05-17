#include "Protagonistaimp.h"
#include "Obstaculo.h"
#include "SueloMeta.h"
#include "SueloNormal.h"
#include "PowerUp.h"
#include "MatrizSuelo.h"
#include "MatrizObstaculos.h"
//#include "matrizSuelo.h"
class Mundo
{
public:
	Mundo() {};

	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	MatrizSuelo msuelo;
	MatrizObstaculos mobs;
	float a[50];
	float b[50];
	float c[50];

	PowerUp *pw1 = new PowerUp;

	Protagonistaimp protagonista, protagonista2;
	
	//matrizSuelo msuelo;
	float x_ojo;
	float y_ojo;
	float z_ojo;
};
