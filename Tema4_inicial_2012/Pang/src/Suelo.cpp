#include "Suelo.h"
#include "glut.h"


Suelo::Suelo( )
{

	colorSuelo.rojo = 100;
	colorSuelo.verde = 200;
	colorSuelo.azul = 50;
}


Suelo::~Suelo()
{
}

void Suelo::Dibuja() {

	glBegin(GL_POLYGON);
	glColor3ub(colorSuelo.rojo, colorSuelo.verde, colorSuelo.azul);
	glVertex3f(centro.x-anchura/2, centro.y-altura/2, 0.0f);
	glVertex3f(centro.x - anchura / 2, centro.y + altura / 2, 0.0f);
	glVertex3f(centro.x + anchura / 2, centro.y + altura / 2, 0.0f);
	glVertex3f(centro.x + anchura / 2, centro.y - altura / 2, 0.0f);
	glEnd();


}
void Suelo::Inicializa(vector2D c, float a, float h) {
	centro = c;
	anchura = a;
	altura = h;

}

vector2D Suelo::GetPosicion() { return centro; }

float Suelo::GetRadio() { return anchura; }
