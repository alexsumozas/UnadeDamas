#include "PowerUp.h"


PowerUp::PowerUp()
{
	tipo = 3;

}


PowerUp::~PowerUp()
{
}

void PowerUp::Dibuja() {

	glColor3ub(200, 0,0);
	glTranslatef(centro.x, centro.y, 0);
	glutSolidSphere(radio, 10, 10);
	glTranslatef(-centro.x, centro.y, 0);
}

void PowerUp::SetCentro(vector2D v) {
	centro = v;

}

unsigned char PowerUp::GetTipo() {

	return this->tipo;
}