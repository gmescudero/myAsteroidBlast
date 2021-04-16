#pragma once

#include "Vector2D.h"
#include "Esfera.h"
#include "Bonus.h"

class Spawn
{
	Vector2D posicion;
	float angulo;
	
public:
	Spawn(void);
	virtual ~Spawn(void);

	void setPos(float x,float y);
	void dibuja();

	Esfera *LanzarAsteroide();
	Bonus *LanzarBonus();
};

