#include "Gimnasio.h"

Gimnasio::Gimnasio() : cursos(new Lista<Curso>())
{
}

Gimnasio::~Gimnasio()
{
	delete cursos;
}

void Gimnasio::agregarCurso(Curso* curso)
{
	cursos->agregar(curso);
}

string Gimnasio::listaCurso()
{
	return cursos ;
}
