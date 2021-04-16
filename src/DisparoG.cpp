
#include "ListaDisparos.h"
#include "Disparo.h"
#include "glut.h"
#include "Vector2D.h"
#include "DisparoG.h"


DisparoG::DisparoG(void)
{
	radio=1.0f;
}


DisparoG::~DisparoG(void)
{
}


void DisparoG::dibuja()
{
	glColor3f(0.0f,1.0f,1.0f);

	glDisable(GL_LIGHTING);
	/*glBegin(GL_LINES);
		glVertex3f(origen.x,origen.y,0);
		glVertex3f(posicion.x,posicion.y,0);
	glEnd();*/
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,0);

   	glColor3f(1.0f, 1.0f, 1.0f); 
	glBegin(GL_QUADS); 

	/*glVertex2f(-0.1f, 0.5f);
	glVertex2f(0.1f,0.5f);
	glVertex2f(0.1f, 1.0f);
	glVertex2f(-0.1f, 1.0f);*/
	if(velocidad.y>0){
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f,0.5f);
		glVertex2f(0.5f, 1.5f);
		glVertex2f(-0.5f, 1.5f);

	}else if(velocidad.y<0){
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, -1.5f);
		glVertex2f(-0.5f, -1.5f);

	}else if(velocidad.x>0){
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(1.5f, -0.5f);
		glVertex2f(1.5f, 0.5f);

	}else if(velocidad.x<0){
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-1.5f, -0.5f);
		glVertex2f(-1.5f, 0.5f);

	}else if((velocidad.x==0)&&(velocidad.y==0)){
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f,0.5f);
		glVertex2f(0.5f, 1.5f);
		glVertex2f(-0.5f, 1.5f);
		
	}
	glEnd();
	glPopMatrix();

}