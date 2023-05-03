#include "Grupo.h"
#include <sstream>
using namespace std;

Grupo::Grupo(int numero, int capacidad) : numero(numero), capacidad(capacidad), cantidadMatriculados(0)
{
}

Grupo::~Grupo()
{
}

int Grupo::getNumero()
{
	return numero;
}

void Grupo::incrementarCantidadMatriculados()
{
	cantidadMatriculados++;
}

string Grupo::toString() const
{
	stringstream x;

	x << "Numero del curso: " << numero << endl;
	x << "Capacidad del grupo: " << capacidad << endl;;
	x << "Cantidad de matriculados: " << cantidadMatriculados << endl;

	return x.str();
}

