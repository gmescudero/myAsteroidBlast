

#include "Nave.h"
#include "glut.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Hombre::Hombre()
{
	color.set(255,100,0);
	posicion.x=0;
	posicion.y=0;
	escudo=false;
	bonus=false;
}

Hombre::~Hombre()
{

}

/////////////////////////////////////////////////////////////////////

void Hombre::dibuja()
{
	
	if (escudo){
		glColor3ub(0,0,255);
		glTranslatef(posicion.x,posicion.y,0);
		glutWireSphere(1.8f,10,10);
		glTranslatef(-posicion.x,-posicion.y,0);
	}

	color.ponColor();

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	if(velocidad.y>0){

		glVertex3d(posicion.x+0.5,posicion.y,0);
		glVertex3d(posicion.x,posicion.y+1,0);
		glVertex3d(posicion.x-0.5,posicion.y,0);
		
	}else if(velocidad.y<0){

		glVertex3d(posicion.x+0.5,posicion.y,0);
		glVertex3d(posicion.x,posicion.y-1,0);
		glVertex3d(posicion.x-0.5,posicion.y,0);

	}else if(velocidad.x>0){
		
		glVertex3d(posicion.x,posicion.y+0.5,0);
		glVertex3d(posicion.x+1,posicion.y,0);
		glVertex3d(posicion.x,posicion.y-0.5,0);

	}else if(velocidad.x<0){
		
		glVertex3d(posicion.x,posicion.y+0.5,0);
		glVertex3d(posicion.x-1,posicion.y,0);
		glVertex3d(posicion.x,posicion.y-0.5,0);

	}else if((velocidad.x==0)&&(velocidad.y==0)){
		
		glVertex3d(posicion.x+0.5,posicion.y,0);
		glVertex3d(posicion.x,posicion.y+1,0);
		glVertex3d(posicion.x-0.5,posicion.y,0);
		
	}

	glEnd();
	glEnable(GL_LIGHTING);
}

void Hombre::setVel(float vx, float vy)
{
	velocidad.x=vx;
	velocidad.y=vy;
}
