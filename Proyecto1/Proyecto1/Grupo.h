#pragma once
#include "ObjetoBase.h"
#include <string>
using namespace std;

class Grupo : public ObjetoBase
{
public:
	Grupo(int);
	virtual ~Grupo();
	virtual int getNumero();
	virtual void incrementarCantidadMatriculados();
	virtual string toString() const;

private:
	int numero;
	int capacidad;
	int cantidadMatriculados;
};

