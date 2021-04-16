#include "Coordinador.h"
#include "ETSIDI.h"
#include "Vidas.h"


CCoordinador::CCoordinador(void)
{
	estado=INICIO; 
}


CCoordinador::~CCoordinador(void)
{
}


void CCoordinador::dibuja() {
	if(estado==INICIO)
 {
	 gluLookAt(0, 7.5, 30, // posicion del ojo
	 0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
	 0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	 ETSIDI::setTextColor(1,1,0);
	 ETSIDI::setFont("fuentes/Bitwise.ttf",16);
	ETSIDI::printxy("Asteroid", -5,8);
	ETSIDI::setTextColor(1,1,1);
	ETSIDI::setFont("fuentes/Bitwise.ttf",12);
	ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5,7); 
	ETSIDI::printxy("Moreno y Gonzalez",2,1);
	} else if(estado==JUEGO){
 mundo.dibuja();
 }
 else if(estado==GAMEOVER)
 {
 gluLookAt(0, 7.5, 30, // posicion del ojo
	 0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
	 0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
 ETSIDI::setTextColor(1,0,0);
 ETSIDI::setFont("fuentes/Bitwise.ttf",16);
 ETSIDI::printxy("GAMEOVER: Has perdido",-5,10);
 ETSIDI::printxy("Pulsa -C- para continuar",-5,5);
 }
 
} 



void CCoordinador::teclaEspecial(unsigned char key)
{
 if(estado==JUEGO)
 mundo.teclaEspecial(key);
}
void CCoordinador::mueve()
{
 if(estado==JUEGO){
	mundo.mueve();
	if(mundo.getVid())
		estado=GAMEOVER;
	
 }
} 

void CCoordinador::tecla(unsigned char key)
{
 if(estado==INICIO)
 {
 if(key=='e')
 {
 estado=JUEGO;
 }
 if(key=='s')
 exit(0);
 }
 else if(estado==JUEGO)
 {
	  mundo.tecla(key);
 }
 else if(estado==GAMEOVER)
 {
 if(key=='c'){
	 estado=INICIO;
	 mundo.restart();
  }
} 
}