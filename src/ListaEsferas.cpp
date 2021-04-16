#include "ListaEsferas.h"
#include "Interaccion.h"
#include "Nave.h"
///////////////////////////////////////////////////////
ListaEsferas::ListaEsferas()
{
	numero=0;
	for(int i=0;i<MAX_ESFERAS;i++)
		lista[i]=0;
}

ListaEsferas::~ListaEsferas(void)
{
	destruirContenido();
}
/////////////////////////////////////////////////////////
void ListaEsferas::destruirContenido()
{
	for(int i=0;i<numero;i++)
		delete lista[i];
	numero=0;
}

bool ListaEsferas::agregar (Esfera *e)
{
	for (int i=0;i<numero;i++)
	{
		if(lista[i]==e)return false;
	}
	if(numero<MAX_ESFERAS)
		lista[numero++]=e;
	else
		return false;
	return true;
}

void ListaEsferas::dibuja()
{
	for(int i=0;i<numero;i++)
		lista[i]->dibuja();
}

void ListaEsferas::mueve(float t)
{
	for(int i=0;i<numero;i++)
		lista[i]->mueve(t);
}



Esfera *ListaEsferas::escape()
{
	for (int i=0;i<numero;i++){
		Interaccion::escape(*lista[i]);
	}
	return 0;
}

void ListaEsferas::rebote()
{
	for(int j=0;j<numero;j++){
		for(int i=0;i<numero;i++)
			Interaccion::rebote(*(lista[i]),*(lista[j]));
	}
}

void ListaEsferas::eliminar(int index)
{
	if((index<0)||(index>=numero))return;

	delete lista[index];
	numero--;
	for(int i=index;i<numero;i++)
		lista[i]=lista[i+1];
}

void ListaEsferas::eliminar(Esfera *e)
{	
	for(int i=0;i<numero;i++)
		if(lista[i]==e)
		{
			eliminar(i);
			return;
		}
}

Esfera * ListaEsferas::colision(Hombre &h)
{
	for(int i=0;i<numero;i++)
	{
		if(Interaccion::colision(*(lista[i]),h))
			return lista[i];
	}
	return 0; //no hay colisi�n
}



Esfera *ListaEsferas::operator [](int i)
{
	if(i>=numero)//si me paso, devuelvo la ultima
		i=numero-1;
	if(i<0) //si el indice es negativo, devuelvo la primera
		i=0;
	return lista[i];
}