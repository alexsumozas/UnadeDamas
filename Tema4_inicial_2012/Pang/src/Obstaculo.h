#pragma once
#include "Color.h"
#include "glut.h"
#include "vector2D.h"
class Obstaculo
{
public:
	Obstaculo(float r, vector2D pos);
	~Obstaculo();
	void Dibuja();
	void Mueve(float a[50],float b[50]);
	
	vector2D GetPosicion();
	float trayectoria[200];
	int contador;
	float radio;
	Color colorObstaculo;
	vector2D posicion;
};

