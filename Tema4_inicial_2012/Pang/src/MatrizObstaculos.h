#pragma once
#include "Obstaculo.h"
#define F 15
#define C 15

class MatrizObstaculos
{

public:
	MatrizObstaculos();
	~MatrizObstaculos();

	int matriz[F][C];
	Obstaculo *obs[F][C];
	void Inicializa();
	void Dibuja();
	void Mueve(float a[50],float b[50]);
	
};

