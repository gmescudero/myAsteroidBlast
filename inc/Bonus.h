
#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"
class Bonus:public ObjetoMovil  
{
	friend class Interaccion;
	friend class Mundo;
public:
	Bonus(float x,float y,float vx, float vy,int t);
	virtual ~Bonus();

	void dibuja();
	void setPos(float ix,float iy);
private:
	float lado;
	int tipo;
/*	tipo 0 - escudo
	tipo 1 - disparo triple
	tipo 2 - disparo guay	*/

};

