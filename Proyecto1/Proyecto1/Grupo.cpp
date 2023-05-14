#include "Grupo.h"
#include <sstream>
using namespace std;

Grupo::Grupo(int numero, int capacidad) : numero(numero), capacidad(capacidad), cantidadMatriculados(0), depo(new Lista<Deportista>())
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

void Grupo::agregarDepor(Deportista* dep)
{
	depo->agregar(dep);
}

string Grupo::toString() const
{
	stringstream x;

	x << "Numero del grupo: " << numero << endl;
	x << "Capacidad del grupo: " << capacidad << endl;;
	x << "Cantidad de matriculados: " << cantidadMatriculados << endl;

	return x.str();
}

string Grupo::listaDeportistas() const
{
	stringstream z;
	Deportista* dep;
	IteradorLista<Deportista>* d;
	d = depo->obtenerIterador();
	while (d->masElementos()) {
		dep = d->proximoElemento();
		z << "\n" << dep->toString() << endl;
	}
	return z.str();
}