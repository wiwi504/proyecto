#pragma once
#include <string>
using namespace std;

class Grupo
{
public:
	Grupo(int);
	virtual ~Grupo();
	virtual int getNumero();
	virtual void incrementarCantidadMatriculados();
	virtual string toString();

private:
	int numero;
	int capacidad;
	int cantidadMatriculados;
};

