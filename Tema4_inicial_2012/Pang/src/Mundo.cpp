#include "Mundo.h"
#include "glut.h"
#include <math.h>
#include <cstdio>




void Mundo::RotarOjo()
{
	float dist = sqrt(x_ojo*x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}
void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		7.5, 6.5, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0,1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
//dibujo del suelo
	glDisable(GL_LIGHTING);

	protagonista.Dibuja();
	//protagonista2.Dibuja();

	
	
	//msuelo.Dibuja();
	msuelo.Dibuja();
	mobs.Dibuja();
	
	
	pw1->Dibuja();
	glEnable(GL_LIGHTING);
}

void Mundo::Mueve()
{
	protagonista.Colision(mobs);
	mobs.Mueve(a, c);
	
	if (protagonista.ColisionPw(pw1) == true) {
		delete pw1;

	}
	protagonista.SalirCamino(msuelo);
	
}

void Mundo::Inicializa()
{
	x_ojo = 7.5;
	y_ojo = 6.5;
	z_ojo = 20;
	vector2D posprota(1, 2);
	posprota=msuelo.matrizInicializa();
	Color colorprota(255, 0, 20);
	protagonista.Inicializa(0.3, 0.3, 3, posprota, colorprota, 1);
	protagonista.posrespawn = posprota;

	vector2D posobstaculo(6, 5);
	Color colorobstaculo(255, 255, 0);

	mobs.Inicializa();
	pw1->radio = 0.41;
	a[0] = 0.1;

	for (int i = 1; i <= 25; i++) {
		a[i] = 0.2 + a[i - 1];
		c[i] = 0;
	}
	for (int i = 26; i < 50; i++) {
		a[i] = a[25+(i-26)]-0.2;
		c[i] = 0;
	}
	vector2D centropw(+3, +6);
	pw1->SetCentro(centropw);

}

void Mundo::Tecla(unsigned char key)
{
	protagonista.Mueve(key);
	
	

}
