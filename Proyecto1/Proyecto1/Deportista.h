#pragma once

#include "ObjetoBase.h"
#include <string>
using namespace std;

class Deportista : public ObjetoBase
{
public:
	Deportista(string, string, int, char);
	virtual ~Deportista();

	virtual string toString() const;

	//Hacer metodo para obtener fecha de nacimiento por día, mes y año.
	//pedir fecha de registro

private:
	string id;
	string nombre;
	int telefono;
	char sexo;
	//Fecha* fechaNacim;
	//Fecha* fechaRegistro;
};