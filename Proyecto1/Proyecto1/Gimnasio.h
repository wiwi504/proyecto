#pragma once
#include "Curso.h"
class Gimnasio
{
public:
	Gimnasio();
	virtual ~Gimnasio();
	virtual void agregarCurso(Curso*);
	virtual string listaCurso();
	virtual string listaCursoConGrupo();

private:
	Lista<Curso>* cursos;
};

//maneja a los triatletas y permite matricular los cursos