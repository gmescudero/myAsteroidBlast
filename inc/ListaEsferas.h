#pragma once
#include <Esfera.h>
#include <Limites.h>
#include"Nave.h"

#define MAX_ESFERAS 100

class ListaEsferas
{
	Esfera * lista[MAX_ESFERAS];
	int numero;

public:
	ListaEsferas(void);
	virtual ~ListaEsferas(void);
	void destruirContenido();

	friend class Mundo;

	bool agregar (Esfera *e);
	void mueve(float t);
	void dibuja();

	void rebote();

	int getNumero(){return numero;}

	void eliminar(int index);
	void eliminar(Esfera *e);

	Esfera *colision(Hombre &h);
	Esfera *escape();

	Esfera *operator [](int i);
};

