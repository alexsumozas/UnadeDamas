
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<iostream>
#include<string>
#include <freeglut.h>
#include "ETSIDI.h"

#define HOMBRE_BOTTOM_Y 12
#define OBST_BOTTOM_Y 20
#define OBST_BOTTOM_X 45
#define OBST_HIGH_Y 20
#define OBST_HIGH_X 70

using namespace std;

//Tamano de consolas
void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("Juego de saltos. Impossible endless game");
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 18);
}

//Dibujo Fondo
void Dibuja()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-10, 0);
	glTexCoord2d(1, 1); glVertex2f(10, 0);
	glTexCoord2d(1, 0); glVertex2f(10, 15);
	glTexCoord2d(0, 0); glVertex2f(-10, 15);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//entrada de tecla
int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

//Dibujo
void DrawHombre(int dinoY)
{
	GotoXY(0, dinoY);
	static bool legFlag = true;
	

	/*
	cout << "    xxxxxxxx		" << endl;
	cout << "  xxxxxxxxxxx		" << endl;
	cout << " xxxxx	 xxxxxxx		" << endl;
	cout << "  xxxxxxxxxxxxxx	" << endl;
	cout << "   xxxxxx	" << endl;
	cout << "    xxxxxxxxxxxxx			" << endl;
	*/


	cout << ""             "" << endl;
	cout << ""             "" << endl;
	cout << ""             "" << endl;
	cout << ""             "" << endl;
	cout << ""             "" << endl;
	cout << ""             "" << endl;
	cout <<"    xxxxx "<< endl;
	cout << "  xxxxxxxxx  " << endl;
	cout << " xxxxxxxxxxx " << endl;
	cout << " xxxxxxxxxxx " << endl;
	cout << "  xxxxxxxxx " << endl;
	cout << "   xxxxxxx	" << endl;

	/*
	if (legFlag)
	{
		printf("     $    $$$    \n");
		printf("     $$          ");
		legFlag = false;
	}
	else
	{
		printf("     $$$  $     \n");
		printf("          $$    ");
		legFlag = true;
	}*/
}

//Crear obstaculos
void DrawObs_1(int ObstX)
{
	GotoXY(ObstX, OBST_BOTTOM_Y);
	printf("    $");
	GotoXY(ObstX, OBST_BOTTOM_Y + 1);
	printf("    $$ ");
	GotoXY(ObstX, OBST_BOTTOM_Y + 2);
	printf("   $$$ ");
	GotoXY(ObstX, OBST_BOTTOM_Y + 3);
	printf("  $$$$ ");
	GotoXY(ObstX, OBST_BOTTOM_Y + 4);
	printf("$$$$$$$$ ");


}




//Poner GameOVER
void DrawGameOver(const int score)
{
	system("cls");
	int x = 18;
	int y = 8;
	GotoXY(x, y);
	printf("===========================");
	GotoXY(x, y + 1);
	printf("======G A M E O V E R======");
	GotoXY(x, y + 2);
	printf("===========================");
	GotoXY(x, y + 5);
	printf("Puntos : %d", score);

	printf("\n\n\n\n\n\n\n\n\n");
	system("pause");
}

//True cuando se choca, si no se choca es false
bool isCollision(const int Obst, const int hombre)
{
	//Cuando x de obstaculo esta cuerpo de hombre
	//si la altura de hombre no es suficiente, se considera como collision
	GotoXY(0, 0);
	printf("Obstaculo : %d, Hombre : %d", Obst, hombre); //이런식으로 적절한 X, Y를 찾습니다.
	if (Obst <= 8 && Obst >= 4 &&
		hombre > 8)
	{
		return true;
	}
	return false;
}

int main()
{
	SetConsoleView();

	while (true)		
	{
		//inicializacion = = salto igual a 0 
		bool isJumping = false;
		bool isBottom = true;
		const int gravity = 3;

		int hombre = HOMBRE_BOTTOM_Y;
		int obst = OBST_BOTTOM_X;
		//int obst_1 = OBST_HIGH_X;

		int score = 0;
		clock_t start, curr;	//incializacion de puntos
		start = clock();		//inicializacion de tiempo

		while (true)	//Loop
		{
			
			if (isCollision(obst, hombre))
				break;

			//salto cunado pulsa x y cuando esta suelo
			if (GetKeyDown() == 'z' && isBottom)
			{
				isJumping = true;
				isBottom = false;
			}

			//disminuye Y cuando está en salto y cuando termina el salto incrementa Y 
			if (isJumping)
			{
				hombre -= gravity;
			}
			else
			{
				hombre += gravity;
			}

			//Poner suelo o limite para el valor de Y
			if (hombre >= HOMBRE_BOTTOM_Y)
			{
				hombre = HOMBRE_BOTTOM_Y;
				isBottom = true;
			}

			//나무가 왼쪽으로 (x음수) 가도록하고
			//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
			obst -= 2;
			if (obst <= 0)
			{
				obst = OBST_BOTTOM_X;
			}

			/*
			obst_1 -= 2;
			if (obst_1 <= 0)
			{
				obst_1 = OBST_HIGH_X;
			}
			*/

			//점프의 맨위를 찍으면 점프가 끝난 상황.
			if (hombre <= 3)
			{
				isJumping = false;
			}

			DrawHombre(hombre);		
			DrawObs_1(obst);		
			//DrawObs_2(obst_1); 

			//(v2.0)
			curr = clock();			//TIempo actual
			if (((curr - start) / CLOCKS_PER_SEC) >= 1)	// Pasa mas de un segundo
			{
				score++;	//sube puntos
				start = clock();	//inicializacion tiempo
			}
			Sleep(60);
			system("cls");	//clear

			
			GotoXY(22, 0);	
			printf("Score : %d ", score);	//Salida punto
		}

		//Game over
		DrawGameOver(score);
	}
	return 0;
}