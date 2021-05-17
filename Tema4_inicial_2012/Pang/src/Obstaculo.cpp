#include "Obstaculo.h"



Obstaculo::Obstaculo(float r, vector2D pos)
{
	radio = r;
	posicion = pos;
	Color col(0, 255, 255);
	colorObstaculo = col;
	contador = 0;

}


Obstaculo::~Obstaculo()
{
}

void Obstaculo::Dibuja() {
	glColor3ub(colorObstaculo.rojo, colorObstaculo.verde, colorObstaculo.azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 10, 10);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Obstaculo::Mueve(float a[50],float b[50] ) {
	if (contador == 45)
		contador = 0;
	else
		posicion.x = a[contador];
	posicion.y = b[contador];

	contador = contador + 1;

}


vector2D Obstaculo::GetPosicion() {

	return posicion;
}