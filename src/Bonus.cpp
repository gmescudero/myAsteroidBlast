
#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Bonus::Bonus(float x,float y,float vx, float vy,int t)
{
	posicion.x=x;
	posicion.y=y;
	velocidad.x=vx;
	velocidad.y=vy;
	tipo=t;
	lado=0.5f;
}

Bonus::~Bonus()
{

}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,0);
	glRotatef(30,1,1,1);
	glColor3f(	rand()/(float)RAND_MAX,
			rand()/(float)RAND_MAX,
			rand()/(float)RAND_MAX);//color aleatorio
    	glutSolidCube(lado);
	glPopMatrix();

}

void Bonus::setPos(float ix,float iy)
{
	posicion.x=ix;
	posicion.y=iy;
}	