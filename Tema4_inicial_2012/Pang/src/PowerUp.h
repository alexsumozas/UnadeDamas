#pragma once
#include "glut.h"
#include "vector2D.h"


class PowerUp
{
public:
	PowerUp();
	~PowerUp();
	float radio;
	unsigned char  tipo; 
	vector2D centro;
	void Dibuja();
	void SetCentro(vector2D);
	unsigned char GetTipo();

};

