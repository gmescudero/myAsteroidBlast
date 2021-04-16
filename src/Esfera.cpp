

#include "Esfera.h"
#include "glut.h"
#include "Disparo.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Esfera::Esfera()
{
	radio=1.0f;
	velocidad.x=4;
	velocidad.y=4;
}

Esfera::Esfera(float rad, float x, float y, float vx, float vy)
{
	radio=rad;
	posicion.x=x;
	posicion.y=y;
	velocidad.x=vx;
	velocidad.y=vy;
	color.set(255,255,100);
}

Esfera::~Esfera(){}

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////

void Esfera::dibuja()
{
	color.ponColor();
	glTranslatef(posicion.x,posicion.y,0);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,0);
}

void Esfera::setColor( Byte r,Byte v, Byte a)
{
	color.set(r,v,a);
}
void Esfera::setRadio(float r)
{
	if(r<0.1F)
		r=0.1F;
	radio=r;
}	

void Esfera::setPos(float ix,float iy)
{
	posicion.x=ix;
	posicion.y=iy;
}

void Esfera::setVel(float vx, float vy)
{
	velocidad.x=vx;
	velocidad.y=vy;
}
void  Esfera::setVel(Vector2D v){
	velocidad=v;
}

Esfera* Esfera::dividir(Disparo d){
	if(radio<1.0f)return 0; //no dividimos

	radio/=2.0f;//Dividimos el radio por 2
	//Creamos una esfera nueva, copiando la actual
	Esfera *aux=new Esfera(*this);
	//Les damos nuevas velocidades

	aux->setVel(d.getVel().unitario().normal()*velocidad.modulo());//a la nueva mitad
	setVel((d.getVel().unitario().normal()*-1.0f)*velocidad.modulo());//a la mitad original
	return aux;
}