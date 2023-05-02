#pragma once

#include "ObjetoBase.h"
#include "DatosBio.h"
#include "Fecha.h"
#include <string>
using namespace std;

class Deportista : public ObjetoBase
{
public:
	Deportista(string, string, string, char, DatosBio*);
	virtual ~Deportista();

	virtual void setId(string);
	virtual void setNombre(string);
	virtual void setTelefono(string);
	virtual void setSexo(char);

	virtual string getId();
	virtual string getNombre();
	virtual string getTelefono();
	virtual char getsexo();

	virtual string toString() const;

private:
	string id;
	string nombre;
	string telefono;
	char sexo;
	DatosBio* datosBio;
	Fecha* fechaNacim;
	//Fecha* fechaRegistro;
};