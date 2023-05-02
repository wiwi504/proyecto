#include "Grupo.h"
#include <sstream>
using namespace std;

Grupo::Grupo(int numero) : numero(numero), capacidad(20), cantidadMatriculados(0)
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

	x << "Numero del curso: " << numero;
	x << "Capacidad del grupo: " << capacidad;
	x << "Cantidad de matriculados: " << cantidadMatriculados;

	return x.str();
}

