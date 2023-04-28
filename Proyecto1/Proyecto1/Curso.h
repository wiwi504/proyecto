#pragma once
#include <string>
using std::string;

#include "Lista.h"
#include "Grupo.h"

class Curso
{
public:
	Curso(string);
	virtual ~Curso();
	void agregarGrupo(Lista<Grupo>*);
	string toString();

private:
	string nombre;
	Lista<Grupo>* grupos;
};


