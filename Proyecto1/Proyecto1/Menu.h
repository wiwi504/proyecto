#pragma once
#include "Lista.h"
#include "Deportista.h"
#include "Curso.h"
#include "Gimnasio.h"

#include <string>
using namespace std;

class Menu
{
public:
	Menu();
	virtual ~Menu();
	virtual void menuPrincipal();
	virtual void iniciar();

private:
	int opcion;
	Lista<Deportista>* deportistas;
	DatosBio* bios;
	Gimnasio* gym;
	Lista<Grupo>* grupos;
};
