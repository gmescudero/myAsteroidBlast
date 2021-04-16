#pragma once

#include "Nave.h"
#include "Limites.h"
#include "Esfera.h"
#include "Disparo.h"
#include "Bonus.h"

class Interaccion  
{
public:
	Interaccion();
	virtual ~Interaccion();	
	
	static bool rebote(Esfera& e1, Esfera& e2);
	static bool escape(Esfera& e);

	static bool colision(Hombre& h, Pared p);
	static bool colision(Hombre& h, Caja c);
	static bool colision(Esfera e, Hombre h);

	static bool colision(Disparo &d, Pared p);
	static bool colision(Disparo &d, Caja c);
	static bool colision(Disparo d, Esfera e);
	static bool impacto(Disparo &d, Esfera &e);

	static bool colision(Bonus &b,Hombre &h);
	static bool escape(Bonus&b);

};

