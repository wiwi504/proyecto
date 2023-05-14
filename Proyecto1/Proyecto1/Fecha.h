#pragma once
#include <ctime>
#include <string>
using namespace std;

class Fecha
{
public:
	Fecha(int, int, int);
	virtual ~Fecha();

	virtual void setDia(int);
	virtual void setMes(int);
	virtual void setAnno(int);

	virtual int getDia();
	virtual int getMes();
	virtual int getAnno();

	virtual string FechaActual();
	virtual int difFecha();
	virtual int dif2(Fecha*) const;
	virtual string toString();

private:
	int dia;
	int mes;
	int anno;
};

