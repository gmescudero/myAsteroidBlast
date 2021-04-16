#pragma once

#include "Limites.h"	
#include "Nave.h"	
#include "Esfera.h"	
#include "Bonus.h"	
#include "Disparo.h"
#include "ListaBonus.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "Spawn.h"
#include "Vidas.h"

class Mundo
{
	Vidas vida;
	ListaBonus bonus;
	ListaEsferas esferas;
	ListaDisparos disparos;
	Hombre hombre;
	Caja caja;
	Spawn sIzq;
	Spawn sDcha;
	Spawn sUp;
	Spawn sDown;
	float x_ojo;
	float y_ojo;
	float z_ojo;

	float tiempo;
	float tiempoIni;
public: 
	Mundo();
	~Mundo();


	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	bool getVid(){if(vida.getVidas()==0)return true;return false;}
	int getPunt(){return vida.getPunt();}
	void setVid() {vida.setVidas(3);}
	void setPunt(){vida.setPunt(0);}
	void restart();
};
