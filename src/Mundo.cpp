#include <cstdlib>
#include "Mundo.h"
#include "glut.h"
#include <math.h>
#include "Vidas.h"
#include "Interaccion.h"
#include "ListaDisparos.h"
#include <ctime>
#include "ObjetoMovil.h"
#include "PrintText.h"
#include <iostream>
#include <string>


Mundo::Mundo()
{

	x_ojo=0;
	y_ojo=0;
	z_ojo=30;	//valor bueno 30
	
	sUp.setPos(0.0f,20.0f);
	sDown.setPos(0.0f,-20.0f);
	sDcha.setPos(24.0f,0.0f);
	sIzq.setPos(-24.0f,0.0f);

	tiempoIni=clock();
}

Mundo::~Mundo()
{
	esferas.destruirContenido();
	disparos.destruirContenido();
	bonus.destruirContenido();
}


void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	esferas.dibuja();
	//caja.dibuja();
	sDcha.dibuja();
	sDown.dibuja();
	sUp.dibuja();
	sIzq.dibuja();
	hombre.dibuja();
	disparos.dibuja();
	vida.dibuja();
	bonus.dibuja();


	std::string s = std::to_string(vida.getPunt());
	char const *pchar = s.c_str();

	PrintText::setTextColor(1,1,1);
	PrintText::setFont("fuentes/Bitwise.ttf",20);
	PrintText::printxy("Puntuacion",-14,6);
	PrintText::printxy(pchar, -7, 6);

}

void Mundo::mueve()
{
	hombre.mueve(0.025f);
	bonus.mueve(0.025f);
	disparos.mueve(0.025f);
	esferas.mueve(0.025f);

	esferas.rebote();
	esferas.escape();
	bonus.escape();
	disparos.colision(caja);
	
	tiempo=clock()-tiempoIni;
	if(tiempo>5000){
		int c= rand() % 6;
		if(c<4){
			switch(c){
			case 0: bonus.agregar(sDcha.LanzarBonus());break;
			case 1: bonus.agregar(sIzq.LanzarBonus());break;
			case 2: bonus.agregar(sUp.LanzarBonus());break;
			case 3: bonus.agregar(sDown.LanzarBonus());break;
			}
		}
		esferas.agregar(sDcha.LanzarAsteroide());
		esferas.agregar(sIzq.LanzarAsteroide());
		esferas.agregar(sUp.LanzarAsteroide());
		esferas.agregar(sDown.LanzarAsteroide());
		tiempoIni=clock();
	}
	
	Interaccion::colision(hombre,caja);

	Esfera *aux=esferas.colision(hombre);
	if(aux!=0){								//si alguna esfera ha chocado con la nave, se elimina y se resta una vida o se quita el escudo si lo hay
		esferas.eliminar(aux);
		if(hombre.getEscudo())hombre.setEscudo(false);
		else --vida;
	}

	Disparo *aux1=disparos.colision(caja);
	if(aux1!=0)									//si algun disparo ha chocado con la caja, se elimina
		disparos.eliminar(aux1);

	Bonus *aux2=bonus.colision(hombre);
	if(aux2!=0){								//si algun bonus ha chocado con la nave, se elimina
		bonus.eliminar(aux2);
		hombre.bonus=true;
	}
	
	for(int i=0;i<esferas.numero;i++)
	{
	
		for(int j=0;j<disparos.numero;j++)
		{
			if(Interaccion::impacto(*disparos[j],*esferas[i]))
			{
				vida.sumaPuntos(100);
				Esfera* e=esferas[i]->dividir(*disparos[j]);
				if(e==0)
				esferas.eliminar(esferas[i]);
				else
				esferas.agregar(e);
				disparos.eliminar(disparos[j]);
				break;
			}
		}
	}
	


}


void Mundo::tecla(unsigned char key)
{
	if((key)==' '){
		if(hombre.bonus==true){
			int c= rand() % 6;
				if(c<4){
					switch(c){
					case 0: {hombre.escudo=true; hombre.bonus=false; break;}
					case 1: { 
						DisparoG* dg=new DisparoG();
						dg->setPos(hombre.getPos());
						dg->setVel(hombre.getVel().unitario()*10);
						disparos.agregar(dg);
						hombre.bonus=false;
							}
					case 2: {
						DisparoM* dm1=new DisparoM();
						dm1->setPos(hombre.getPos());
						dm1->setVel(10.0f, 0.0f);
						disparos.agregar(dm1);

						DisparoM* dm2=new DisparoM();
						dm2->setPos(hombre.getPos());
						dm2->setVel(-10.0f, 0.0f);
						disparos.agregar(dm2);

						DisparoM* dm3=new DisparoM();
						dm3->setPos(hombre.getPos());
						dm3->setVel(0.0f, 10.0f);
						disparos.agregar(dm3);

						DisparoM* dm4=new DisparoM();
						dm4->setPos(hombre.getPos());
						dm4->setVel(0.0f, -10.0f);
						disparos.agregar(dm4);
						hombre.bonus=false;
							}
					//case 3: {}
					}
				}


		}
		else {
			Disparo* d=new Disparo();
				d->setPos(hombre.getPos());
				d->setVel(hombre.getVel().unitario()*10);
				disparos.agregar(d);
		}
		
			/*Disparo* d=new Disparo();
			d->setPos(hombre.getPos());
			d->setVel(hombre.getVel().unitario()*10);
			disparos.agregar(d);*/
}
}

void Mundo::teclaEspecial(unsigned char key)
{
	if(key==GLUT_KEY_LEFT)hombre.setVel (-5.0f, 0.0f);
	else if(key==GLUT_KEY_RIGHT)hombre.setVel (5.0f, 0.0f);
	else if(key==GLUT_KEY_UP)hombre.setVel (0.0f, 5.0f);
	else if(key==GLUT_KEY_DOWN)hombre.setVel (0.0f, -5.0f);
	else hombre.setVel(0.0f,0.0f);
}
void Mundo::restart()
{
	hombre.setVel();
	hombre.setPos();
	setVid();
	setPunt();
	esferas.destruirContenido();
	disparos.destruirContenido();
	bonus.destruirContenido();
	tiempoIni=clock();
	tiempo=clock()-tiempoIni;

}
