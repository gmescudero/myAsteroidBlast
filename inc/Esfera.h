#pragma once


#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"
#include "Disparo.h"
class Esfera:public ObjetoMovil 
{
	friend class Interaccion;
public:
	Esfera();
	Esfera(float rad, float x=0.0f, float y=0.0f,
		float vx=0.0f, float vy=0.0f);
	~Esfera();
	
	void dibuja();

	Esfera* dividir(Disparo d);

	void setColor( Byte r,Byte v, Byte a);
	void setRadio(float r);
	void setPos(float ix,float iy);
	void setVel(float vx, float vy);
	void setVel(Vector2D v);
	Esfera* eliminar();

private:
	ColorRGB color;
	float radio;


};


