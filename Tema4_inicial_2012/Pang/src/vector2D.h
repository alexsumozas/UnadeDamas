#pragma once
class vector2D
{
public:
	vector2D();
	vector2D(float, float);
	~vector2D();
	float modulo();
	float distancia(vector2D);
	float x;
	float y;

	vector2D operator + (vector2D a);

};

