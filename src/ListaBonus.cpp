#include "ListaBonus.h"
#include "Interaccion.h"


ListaBonus::ListaBonus(void)
{
	numero=0;
	for(int i=0;i<MAX_BONUS;i++)
		lista[i]=0;
}


ListaBonus::~ListaBonus(void)
{
	destruirContenido();
}

bool ListaBonus::agregar(Bonus* b)
{
	for (int i=0;i<numero;i++)
	{
		if(lista[i]==b)return false;
	}
	if(numero<MAX_BONUS)
		lista[numero++]=b;
	else
		return false;
	return true;
}

void ListaBonus::destruirContenido()
{
	for(int i=0;i<numero;i++)
		delete lista[i];
	numero=0;
}

void ListaBonus::mueve(float t)
{
	for(int i=0;i<numero;i++)
		lista[i]->mueve(t);
}

void ListaBonus::dibuja()
{
	for(int i=0;i<numero;i++)
		lista[i]->dibuja();
}

void ListaBonus::eliminar(int index)
	{
		if((index<0)||(index>=numero))
			return;
		delete lista[index];
		numero--;
		for(int i=index;i<numero;i++)
			lista[i]=lista[i+1];
}
void ListaBonus::eliminar(Bonus *b)
{
	for(int i=0;i<numero;i++)
		if(lista[i]==b)
		{
			eliminar(i);
			return;
		}
}

Bonus *ListaBonus::operator [](int i)
{
	if(i>=numero)//si me paso, devuelvo la ultima
		i=numero-1;
	if(i<0) //si el indice es negativo, devuelvo la primera
		i=0;
	return lista[i];
}

void ListaBonus::escape()
{
	for(int i=0;i<numero;i++)
		if(Interaccion::escape(*lista[i]))eliminar(i);
}

Bonus *ListaBonus::colision(Hombre &h){
	for(int i=0;i<numero;i++)
	{
		if(Interaccion::colision(*(lista[i]),h))
			return lista[i];
	}
	return 0; //no hay colisión
}