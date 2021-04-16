#pragma once
#define MAX_DISPAROS 1000
#include "Disparo.h"
#include "DisparoG.h"
#include "DisparoM.h"
#include "Limites.h"
#include "Vector2D.h"

class ListaDisparos
{
public:
	ListaDisparos();
	virtual ~ListaDisparos();
	void destruirContenido();

	friend class Mundo;

	bool agregar(Disparo* d);
	//bool agregar(DisparoG* dg);
	void mueve(float t);
	void dibuja();
	void colision(Pared p);
	Disparo *colision(Caja c);

	void eliminar(int index);
	void eliminar(Disparo *d);
	void setVel(float vx, float vy);
	Disparo *operator [](int i);



private:
	Disparo * lista[MAX_DISPAROS];
	int numero;
	
};

