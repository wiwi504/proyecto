#include "Curso.h"
#include <sstream>
using std::stringstream;

Curso::Curso(string nombreCurso, string descripcion, string nivel, string fechas, string horario, int cupoMaximo) : nombreCurso(nombreCurso), descripcion(descripcion), nivel(nivel), fechas(fechas), horario(horario), cupoMaximo(cupoMaximo), grupos(new Lista<Grupo>())
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

string Curso::getFechas() const
{
	return this->fechas;
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
	x << "Fechas: " << fechas << endl;
	x << "Horario: " << horario << endl;
	x << "Cupo M�ximo: " << cupoMaximo << endl;

	return x.str();
}

string Curso::toStringConGrupo() const
{
	stringstream z;

	z << "Curso: " << nombreCurso << endl;
	z << "Descripcion: " << descripcion << endl;
	z << "Nivel: " << nivel << endl;
	z << "Fechas: " << fechas << endl;
	z << "Horario: " << horario << endl;
	z << "Cupo M�ximo: " << cupoMaximo << endl;
	z << "Lista de grupos: " << grupos << endl;

	return z.str();
}