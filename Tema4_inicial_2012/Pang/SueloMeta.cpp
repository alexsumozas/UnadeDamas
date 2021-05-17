#include "src\SueloMeta.h"
#include "vector2D.h"



SueloMeta::SueloMeta(vector2D v)
{
	colorSuelo.azul = 20;
	colorSuelo.verde = 250;
	colorSuelo.rojo = 10;
	Suelo::Inicializa(v, 1, 1);
}


SueloMeta::~SueloMeta()
{
}

void SueloMeta::Inicializa(vector2D v) {
	Suelo::Inicializa(v, 2, 2);

}