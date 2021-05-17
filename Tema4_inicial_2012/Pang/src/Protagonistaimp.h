#pragma once
#include "Color.h"
#include "vector2D.h"
#include "Obstaculo.h"
#include "PowerUp.h"
#include "SueloDecor.h"
#include "MatrizSuelo.h"
#include "MatrizObstaculos.h"
class Protagonistaimp
{
public:
	Protagonistaimp();
	Protagonistaimp(float, float, int);
	~Protagonistaimp();
	void  setColor(Color col);
	void setRadio(float);
	void setPosicion(vector2D);
	void setVidas(int);
	void setVelocidad(float);
	void  Dibuja();
	void Inicializa(float, float, int, vector2D, Color, int);
	void Mueve(unsigned char key);
	bool Colision(MatrizObstaculos);
	bool SalirCamino(MatrizSuelo);
	bool ColisionPw(PowerUp*);
	vector2D posrespawn;

private:
	
	int jugador;
	float  radio;
	Color colorProtagonista;
	int vidas;
	float velocidad;
	vector2D posicion;
	bool invencible;

};

