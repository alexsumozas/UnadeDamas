#include "Protagonistaimp.h"
#include "glut.h"
#include "Obstaculo.h"
#include <math.h>

Protagonistaimp::Protagonistaimp()
{
	radio = 0;
	colorProtagonista.azul = 255;
	colorProtagonista.verde = 0;
	colorProtagonista.rojo =20;
	velocidad = 0;
	posicion.x = 0;
	posicion.y = 0;
	vidas = 0;
}


Protagonistaimp::~Protagonistaimp()
{
}

Protagonistaimp::Protagonistaimp(float rad = 1, float vel = 1, int lifes = 3) {
	jugador = 0;

	radio = rad;
	velocidad = vel;
	vidas = lifes;
}

void Protagonistaimp::setColor(Color col) {

	colorProtagonista = col;
}
void Protagonistaimp::Dibuja() {

	glColor3ub(colorProtagonista.rojo, colorProtagonista.verde, colorProtagonista.azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidCube(radio);
	glTranslatef(-posicion.x, -posicion.y, 0);

}

void Protagonistaimp::setRadio(float r) {
	radio = r;
}
void Protagonistaimp::setVidas(int lifes) {
	vidas = lifes;
}
void Protagonistaimp::setVelocidad(float v) {
	velocidad = v;
}
void Protagonistaimp::setPosicion(vector2D pos) {

	posicion = pos;
}

void Protagonistaimp::Inicializa(float r, float v, int life, vector2D pos, Color c, int j) {

	radio = r;
	velocidad = v;
	vidas = life;
	posicion = pos;
	colorProtagonista = c;
	jugador = j;

}

void Protagonistaimp::Mueve(unsigned char key) {
	if (jugador == 1) {
		if (key == 'd' || key == 'D')
			posicion.x = posicion.x + 1 * velocidad;
		if (key == 'a' || key == 'A')
			posicion.x = posicion.x - 1 * velocidad;
		if (key == 'w' || key == 'W')
			posicion.y = posicion.y + 1 * velocidad;
		if (key == 's' || key == 'S')
			posicion.y = posicion.y - 1 * velocidad;

	}
	else {
		if (key == 'l' || key == 'L')
			posicion.x = posicion.x + 1 * velocidad;
		if (key == 'j' || key == 'J')
			posicion.x = posicion.x - 1 * velocidad;
		if (key == 'i' || key == 'I')
			posicion.y = posicion.y + 1 * velocidad;
		if (key == 'k' || key == 'K')
			posicion.y = posicion.y - 1 * velocidad;
	}
}
bool Protagonistaimp::Colision(MatrizObstaculos mobs) {
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < F; j++) {
			if (mobs.obs[i][j]!=0){
			if (posicion.distancia(mobs.obs[i][j]->GetPosicion()) <= (radio + mobs.obs[i][j]->radio) && invencible == false) {
				if (vidas == 1)
					radio = 0;
				else
				{
					vidas = vidas - 1;
					posicion.x = posrespawn.x; posicion.y = posrespawn.y;
				}

				return true;
			}
			}

		}
	}
	 return false;
}
bool Protagonistaimp::ColisionPw(PowerUp* pw) {

	if (posicion.distancia(pw->centro) <= (radio + pw->radio)) {

		if (pw->GetTipo() == 1) { velocidad = velocidad *2.5; }
		if (pw->GetTipo() == 2) {radio = radio* 2; }
		if (pw->GetTipo() == 3) {
			colorProtagonista.verde = 255; colorProtagonista.azul = 255; colorProtagonista.rojo = 255; invencible = true;
		}
		if (pw->GetTipo() == 4) { velocidad = velocidad * 2; }
		return true;
		

		
	}
	else return false;
}

bool Protagonistaimp::SalirCamino(MatrizSuelo s) {
	for (int i = 0; i < 15;i++) {
		for (int j=0;j<15;j++){
			if (s.spunt[i][j] != NULL){
			
				vector2D aux = s.spunt[i][j]->GetPosicion();
				float raux = s.spunt[i][j]->GetRadio();

				if (sqrt((posicion.x - aux.x)*(posicion.x - aux.x)) <= sqrt(((radio + raux) / 2)*((radio + raux) / 2)) && sqrt((posicion.y - aux.y)*(posicion.y - aux.y)) <= sqrt(((radio + raux) / 2)*((radio + raux) / 2)))
				{
					if (posicion.x - aux.x > 0 && sqrt((posicion.x - aux.x)*(posicion.x - aux.x)) > sqrt((posicion.y - aux.y)*(posicion.y - aux.y)))
					{
						posicion.x = aux.x + radio / 2 + raux / 2+ 0.05; return true;
						
					}
					else if (posicion.x - aux.x < 0 && sqrt((posicion.x - aux.x)*(posicion.x - aux.x))>sqrt((posicion.y - aux.y)*(posicion.y - aux.y)))
					{
						posicion.x = aux.x - radio / 2 - raux / 2-0.05; return true;
					}

					else if (posicion.y - aux.y > 0 && sqrt((posicion.x - aux.x)*(posicion.x - aux.x)) < sqrt((posicion.y - aux.y)*(posicion.y - aux.y)))
					{
						posicion.y = aux.y + radio / 2 + raux / 2+0,05; return true;
					}

					else if (posicion.y - aux.y < 0 && sqrt((posicion.x - aux.x)*(posicion.x - aux.x)) < sqrt((posicion.y - aux.y)*(posicion.y - aux.y)))
					{
						posicion.y = aux.y - radio / 2 - raux / 2 -0.05; return true;
					}
				}
	

		
	}

	}
	}
	return false;
}