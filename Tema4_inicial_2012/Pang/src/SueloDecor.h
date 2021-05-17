#pragma once
#include "Suelo.h"
#include "vector2D.h"

class SueloDecor :public Suelo
{
public:
	SueloDecor(vector2D);
	~SueloDecor();
	void Inicializa(vector2D);
	SueloDecor* siguiente;
	SueloDecor* anterior;
	int numpos;
};

