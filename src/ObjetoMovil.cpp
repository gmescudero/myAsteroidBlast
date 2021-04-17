 #include "ObjetoMovil.h"


ObjetoMovil::ObjetoMovil(void)
{
}


ObjetoMovil::~ObjetoMovil(void)
{
}
void ObjetoMovil::mueve(float t)
{
	Vector2D vt  = velocidad   * t;
	Vector2D at  = aceleracion * t;
	Vector2D att = aceleracion * (0.5f*t*t);

	posicion  = posicion  + vt + att;
	velocidad = velocidad + at;
}