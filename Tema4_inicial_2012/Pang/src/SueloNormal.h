#pragma once
#include "Suelo.h"
#include "vector2D.h"
class SueloNormal : public Suelo
{
public:
	SueloNormal(vector2D);
	~SueloNormal();

	bool pisable;
	void Inicializa(vector2D);

};

