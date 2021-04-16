

#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D(float xv,float yv)
{
	x=xv;
	y=yv;
}

Vector2D::~Vector2D()
{

}

float Vector2D::modulo()
{
	return (float)sqrt(x*x+y*y);
}
float Vector2D::argumento()
{
	return (float)atan2(y,x);
}
Vector2D Vector2D::unitario()
{
	Vector2D retorno(x,y);
	float mod=modulo();
	if(mod>0.00001)
	{
		retorno.x/=mod;
		retorno.y/=mod;
	}
	return retorno;
}
Vector2D Vector2D::operator - (Vector2D &v)
{
	Vector2D res;
	res.x=x-v.x;
	res.y=y-v.y;
	return res;
}


Vector2D Vector2D::operator + (Vector2D &v)
{
	Vector2D res;
	res.x=x+v.x;
	res.y=y+v.y;
	return res;
}
float Vector2D::operator *(Vector2D &v)	
{
	return x*v.x+y*v.y;
}
Vector2D Vector2D::operator *(float f)
{
	Vector2D res;
	res.x=x*f;
	res.y=y*f;
	return res;
}
Vector2D Vector2D::normal()
{
	float paso=x;
	x=y;
	y=paso;
	return *this;
}