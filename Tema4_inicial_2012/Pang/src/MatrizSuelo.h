#pragma once
#include "Suelo.h"
#include "SueloDecor.h"
#include "SueloMeta.h"
#include"SueloNormal.h"
#include "SueloCasa.h"
#define F 15
#define C 15

class MatrizSuelo
{
public:
	MatrizSuelo();
	~MatrizSuelo();

	int matriz[F][C] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,0,0,0,0,0,0,0,0},{1,3,4,2,2,2,1,0,0,0,0,0,0,0,0},{0,1,1,1,2,2,1,0,0,0,0,0,0,0,0},
	{0,0,0,1,2,2,1,1,1,1,1,1,1,0,0},{0,0,0,1,2,2,2,2,2,2,2,2,1,0,0},{0,0,0,1,1,1,1,1,1,1,2,1,0,0,0},{0,0,0,0,0,0,0,0,0,1,2,1,0,0,0},{0,0,0,0,0,0,0,0,0,1,2,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,2,1,0,0,0} ,{0,0,0,0,0,0,0,0,0,1,2,1,0,0,0} ,{0,0,0,0,0,1,1,1,1,1,2,2,1,0,0},{0,0,0,0,1,4,4,2,2,2,2,2,1,0,0},{0,0,0,0,1,4,4,2,2,1,1,1,1,0,0},
	{0,0,0,0,0,1,1,1,1,1,0,0,0,0,0} };
	vector2D matrizInicializa();
	int contador;
	SueloDecor* sd;
	SueloDecor *saux;
	void Dibuja();
	SueloDecor *spunt[C][F];
	SueloNormal *spnormal[C][F];
	SueloMeta * spmeta[C][F];
	SueloCasa *scasa;
	vector2D posrespawn;
};

