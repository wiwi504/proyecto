#pragma once
class DatosBio
{
public:
	DatosBio(double, double, double, double);
	virtual ~DatosBio();

private:
	double estatura;
	double peso;
	double porcGrasaCorpo;
	double porcMasaMuscu;
};
