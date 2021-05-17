#pragma once
#include "vector2D.h"
#include "Color.h"
class Suelo
{

public:
	
	Suelo();
	~Suelo();
	vector2D centro; // se dibujan usando el vértice de arriba
	float anchura;
	float altura;
	Color colorSuelo;
	void Dibuja();
	void Inicializa(vector2D,float,float);
	vector2D GetPosicion();
	float GetRadio();

};

