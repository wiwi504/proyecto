#include "Curso.h"
#include <sstream>
using std::stringstream;

Curso::Curso(string nombreCurso, string descripcion, string nivel, Fecha* fechaInicio, string horario, int cupoMaximo) : nombreCurso(nombreCurso), descripcion(descripcion), nivel(nivel), fechaInicio(fechaInicio), horario(horario), cupoMaximo(cupoMaximo), grupos(new Lista<Grupo>())
{
}

Curso::~Curso()
{
}

string Curso::getNombreCurso() const
{
	return this->nombreCurso;
}

string Curso::getDescripcion() const
{
	return this->descripcion;
}

string Curso::getNivel() const
{
	return this->nivel;
}

string Curso::getHorario() const
{
	return this->horario;
}

int Curso::getCupoMaximo() const
{
	return this->cupoMaximo;
}

void Curso::agregarGrupo(Grupo* grupo)
{
	grupos->agregar(grupo);
}

string Curso::toString() const
{
	stringstream x;

	x << "Curso: " << nombreCurso << endl;
	x << "Descripcion: " << descripcion << endl;
	x << "Nivel: " << nivel << endl;
	x << "Fecha: " << fechaInicio->toString() << endl;
	x << "Horario: " << horario << endl;
	x << "Cupo maximo de grupos: " << cupoMaximo << endl;

	return x.str();
}

string Curso::toStringConGrupo() const
{
	stringstream z;

	z << "Curso: " << nombreCurso << endl;
	z << "Descripcion: " << descripcion << endl;
	z << "Nivel: " << nivel << endl;
	z << "Fecha: " << fechaInicio->toString() << endl;
	z << "Horario: " << horario << endl;
	z << "Cupo maximo de grupos: " << cupoMaximo << endl;

	Grupo* grupo;
	IteradorLista<Grupo>* g;
	g = grupos->obtenerIterador();
	while (g->masElementos()) {
		grupo = g->proximoElemento();
		z << "\nGrupos\n" << grupo->toString() << endl;
		//z << "\nLista de inscritos\n" << grupo->listaDeportistas() << endl;
	}

	return z.str();
}