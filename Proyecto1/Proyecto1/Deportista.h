#pragma once

#include "ObjetoBase.h"
#include <string>
using namespace std;

class Deportista : public ObjetoBase// : public Triatlonista
{
public:
	Deportista(string, string, int, char);
	virtual ~Deportista();

	//set y get
	virtual string getId();
	virtual void setId(string);

	virtual string getNombre();
	virtual void setNombre(string);

	virtual int getTelefono();
	virtual void setTelefono(int);

	virtual char getSexo();
	virtual void setSexo(char);

	virtual string toString() const;

	//Hacer metodo para obtener fecha de nacimiento por día, mes y año.
	//Pedir y obtener datos biométricos.
	//pedir fecha de registro

private:
	string id;
	string nombre;
	int telefono;
	char sexo;
};