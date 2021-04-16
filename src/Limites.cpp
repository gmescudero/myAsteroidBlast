

#include "Limites.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Caja::Caja(float e)
{
	suelo.setColor(0,100,0);
	suelo.setPos(-14.0f-e,-10.0f-e,14.0f+e,-10.0f-e);

	techo.setColor(0,100,0);
	techo.setPos(-14.0f-e,10.0f+e,14.0f+e,10.0f+e);
	
	pared_izq.setColor(0,150,0);
	pared_izq.setPos(-14.0f-e,-10.0f-e,-14.0f-e,10.0f+e);

	pared_dcha.setColor(0,150,0);
	pared_dcha.setPos(14.0f+e,-10.0f-e,14.0f+e,10.0f+e);
}

Caja::~Caja()
{

}

void Caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();

}
