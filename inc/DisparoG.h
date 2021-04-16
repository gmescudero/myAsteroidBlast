#pragma once

#include "Vector2D.h"
#include "Nave.h"
#include "ObjetoMovil.h"
#include "Disparo.h"
class DisparoG :public Disparo
{
public:
	DisparoG(void);
	virtual ~DisparoG(void);

	void dibuja();


private:
	float radio;
};

