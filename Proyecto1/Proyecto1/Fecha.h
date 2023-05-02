#pragma once
#include <cmath>

class Fecha
{
public:
	Fecha(int, int, int);
	virtual ~Fecha();
	virtual int difFecha(const Fecha& fechaInicio) const;
	int edad(const Fecha& fechaNacim) const;
	virtual int registro();

private:
	int dia;
	int mes;
	int anno;

};

