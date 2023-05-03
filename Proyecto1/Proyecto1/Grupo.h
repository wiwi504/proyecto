#pragma once
#include "ObjetoBase.h"

class Grupo : public ObjetoBase
{
public:
	Grupo(int, int);
	virtual ~Grupo();
	virtual int getNumero();
	virtual void incrementarCantidadMatriculados();
	virtual string toString() const;

private:
	int numero;
	int capacidad;
	int cantidadMatriculados;
};

