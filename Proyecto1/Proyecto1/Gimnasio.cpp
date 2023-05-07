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
	Curso* curso;
	IteradorLista<Curso>* c;
	c = cursos->obtenerIterador();
	while (c->masElementos()) {
		curso = c->proximoElemento();
		cout << "\n";
		return curso->toString();
	}
}

string Gimnasio::listaCursoConGrupo()
{
	Curso* curso;
	IteradorLista<Curso>* c;
	c = cursos->obtenerIterador();
	while (c->masElementos()) {
		curso = c->proximoElemento();
		cout << "\n";
		return curso->toStringConGrupo();
	}
}