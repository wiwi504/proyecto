#include "Curso.h"
#include <sstream>
using std::stringstream;

Curso::Curso(string nombre) : nombre(nombre) //no s� c�mo inicializar la plantilla
{
}

Curso::~Curso()
{
}

void Curso::agregarGrupo(Lista<Grupo>* grupo)
{

}

string Curso::toString()
{
	stringstream x;



	return x.str();
}
