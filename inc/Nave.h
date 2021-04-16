
#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"
class Hombre:public ObjetoMovil
{
public:
	Hombre();
	virtual ~Hombre();

	friend class Mundo;
	
	void dibuja();
	void setVel(float vx=0.0f, float vy=0.0f);
	void setPos(float x=0.0f, float y=0.0f){posicion.x=x;posicion.y=y;}
	void setEscudo(bool e){escudo=e;}
	bool getEscudo(){return escudo;}


	
	Vector2D getPos(){return posicion;}
	Vector2D getVel(){return velocidad;}

private:
	ColorRGB color;
	bool escudo;
	bool bonus;

friend class Interaccion;
};

