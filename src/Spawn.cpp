

#include "Spawn.h"
#include "ListaEsferas.h"
#include <cstdlib>
#include <cmath>
#include "glut.h"

Spawn::Spawn(void)
{

}

Spawn::~Spawn(void)
{

}

void Spawn::dibuja()
{
	ColorRGB color(255,255,255);
	color.ponColor();
	glTranslatef(posicion.x,posicion.y,0);
	glutSolidTorus(0.2,0.7,5,5);
	glTranslatef(-posicion.x,-posicion.y,0);
}

void Spawn::setPos(float x,float y)
{
	posicion.x=x;
	posicion.y=y;
	const float pi=3.141592f;
	if(x<-1.0f)angulo=0;
	else if(x>1.0f)angulo=pi;
	else if(y>1.0f)angulo=pi*(3.0f/2.0f);
	else if(y<-1.0f)angulo=pi/2;

}

Esfera *Spawn::LanzarAsteroide() 
{
	float rad=rand() % 3+1;
	float x=posicion.x;
	float y=posicion.y;
	Vector2D v(rand() % 30 -15,rand() % 30 -15);
	v=v*0.5f;
	float vx=v.x*cos(angulo)-v.y*sin(angulo);
	float vy=v.x*sin(angulo)+v.y*cos(angulo);

	Esfera *e =new Esfera(rad,x,y,vx,vy);
	return e;
}

Bonus *Spawn::LanzarBonus()
{
	Bonus *b=new Bonus(posicion.x,posicion.y,5.0f*cos(angulo),5.0f*sin(angulo),rand() % 2);
	return b;
}