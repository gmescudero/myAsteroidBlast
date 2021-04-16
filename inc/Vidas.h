#pragma once
#include "ColorRGB.h"
class Vidas
{
	int vidas;
	int puntos;
	ColorRGB color;
public:
	Vidas(void):vidas(3),puntos(0){color.set(255,0,0);}
	~Vidas(void);

	friend class Mundo;

	void dibuja();
	int getVidas(){return vidas;}
	void setVidas(int v){vidas=v;}
	int getPunt(){return puntos;}
	void setPunt(int p){puntos=p;}

	void sumaPuntos(int p){puntos+=p;}

	Vidas operator--(){vidas--;return *this;}
};

