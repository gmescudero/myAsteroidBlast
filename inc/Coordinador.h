#pragma once

#include "Mundo.h"
class CCoordinador
{
public:
	CCoordinador(void);
	virtual ~CCoordinador(void);

	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
protected:
	Mundo mundo;

protected:
	enum Estado {INICIO, JUEGO, GAMEOVER};
	Estado estado;
};

