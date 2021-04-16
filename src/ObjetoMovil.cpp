 #include "ObjetoMovil.h"


ObjetoMovil::ObjetoMovil(void)
{
}


ObjetoMovil::~ObjetoMovil(void)
{
}
void ObjetoMovil::mueve(float t)
{
	posicion=posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad=velocidad+aceleracion*t;
}