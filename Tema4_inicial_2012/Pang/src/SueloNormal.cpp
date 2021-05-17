#include "SueloNormal.h"



SueloNormal::SueloNormal(vector2D cen)
{
	colorSuelo.azul = 250;
	colorSuelo.verde = 250;
	colorSuelo.rojo = 250;
	Suelo::Inicializa(cen, 1, 1);
}


SueloNormal::~SueloNormal()
{
}

void SueloNormal::Inicializa(vector2D cen) {
	Suelo::Inicializa(cen, 1, 1);
	

}

