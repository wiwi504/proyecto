#include "Gimnasio.h"
#include <sstream>
using std::stringstream;

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
	stringstream x;
	Curso* curso;
	IteradorLista<Curso>* c;
	c = cursos->obtenerIterador();
	while (c->masElementos()) {
		curso = c->proximoElemento();
		x << "\n";
		x << curso->toString();
	}
	return x.str();
}

string Gimnasio::listaCursoConGrupo()
{
	stringstream x;
	Curso* curso;
	IteradorLista<Curso>* c;
	c = cursos->obtenerIterador();
	while (c->masElementos()) {
		curso = c->proximoElemento();
		x << "\n";
		x << curso->toStringConGrupo();
	}
	return x.str();
}