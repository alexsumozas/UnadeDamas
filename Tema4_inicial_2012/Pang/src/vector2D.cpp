#include "vector2D.h"
#include <math.h>


vector2D::vector2D()
{
}
vector2D::vector2D(float ix, float iy)
{
	x = ix;
	y = iy;
}


vector2D::~vector2D()
{
}

float vector2D::modulo() {

	return sqrt(x*x + y * y);
}

float vector2D::distancia(vector2D a) {
	float auxx = x - a.x;
	float auxy = y - a.y;
	return sqrt(auxx*auxx + auxy * auxy);


}

vector2D vector2D::operator + (vector2D a) {
	vector2D auxiliar;
	auxiliar.x = this->x + a.x;
	auxiliar.y = this->y + a.y;

	return auxiliar;
}