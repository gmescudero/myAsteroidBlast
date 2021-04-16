#pragma once
#define MAX_BONUS 4
#include "Bonus.h"
#include "Nave.h"

class ListaBonus
{
	Bonus * lista[MAX_BONUS];
	int numero;
public:
	ListaBonus(void);
	virtual ~ListaBonus(void);
	void destruirContenido();

	bool agregar(Bonus* b);
	void mueve(float t);
	void dibuja();

	void eliminar(int index);
	void eliminar(Bonus *b);

	void escape();
	Bonus *colision(Hombre &h);

	Bonus *operator [](int i);
};

