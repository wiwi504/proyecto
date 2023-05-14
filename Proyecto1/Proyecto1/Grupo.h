#pragma once
#include "ObjetoBase.h"
#include "Deportista.h"
#include "Lista.h"

class Grupo : public ObjetoBase
{
public:
	Grupo(int, int);
	virtual ~Grupo();
	virtual int getNumero();
	virtual void incrementarCantidadMatriculados();
	void agregarDepor(Deportista*);
	virtual string toString() const;
	virtual string listaDeportistas() const;

private:
	int numero;
	int capacidad;
	int cantidadMatriculados;
	Lista<Deportista>* depo;
};

