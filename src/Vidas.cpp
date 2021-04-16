#include "Vidas.h"
#include "glut.h"



Vidas::~Vidas(void)
{
}

void Vidas::dibuja()
{
	color.ponColor();
	for(int i=0;i<vidas;i++){
		glTranslatef(-10.0f+i*2.0f,7.0f,5);
		glutSolidSphere(1.0f,20,20);
		glTranslatef(10.0f-i*2.0f,-7.0f,-5);
	}
}