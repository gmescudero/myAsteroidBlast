
#pragma once

#include "Vector2D.h"
#include "Nave.h"
#include "ObjetoMovil.h"
class Disparo:public ObjetoMovil
{
	friend class Interaccion;
public:
	Disparo();
	virtual ~Disparo();

	friend class Mundo;
	friend class ListaDisparos;
	

	void dibuja();

	void setPos(float ix,float iy);
	void setPos(Vector2D p);
	void setVel(float vx, float vy);
	void setVel(Vector2D v);
	

	float getRadio(){return radio;}
	Vector2D getPos(){return posicion;}
	Vector2D getVel(){return velocidad;}

private:
	float radio;

	Vector2D origen;

};
