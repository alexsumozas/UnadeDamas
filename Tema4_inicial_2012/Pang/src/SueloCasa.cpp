#include "SueloCasa.h"



SueloCasa::SueloCasa(vector2D v)
{
	colorSuelo.azul = 20;
	colorSuelo.verde = 250;
	colorSuelo.rojo = 10;
	Suelo::Inicializa(v, 1, 1);
}


SueloCasa::~SueloCasa()
{
}

