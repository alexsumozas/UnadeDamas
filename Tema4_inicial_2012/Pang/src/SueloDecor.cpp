#include "SueloDecor.h"



SueloDecor::SueloDecor(vector2D v)
{

	colorSuelo.rojo = 10;
	colorSuelo.verde = 00;
	colorSuelo.azul = 250;
	Suelo::Inicializa(v, 1, 1);
}


SueloDecor::~SueloDecor()
{
}

void SueloDecor::Inicializa(vector2D v) {
	//Suelo::Inicializa(v, 3, 3);

}
