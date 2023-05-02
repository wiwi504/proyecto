#pragma once
#include "Curso.h"
class Gimnasio
{
public:
	Gimnasio();
	virtual ~Gimnasio();
	void agregarCurso(Curso*);
	string listaCurso();

private:
	Lista<Curso>* cursos;
};

//maneja a los triatletas y permite matricular los cursos