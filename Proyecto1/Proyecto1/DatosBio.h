#pragma once
class DatosBio
{
public:
	DatosBio(double, double, double, double);
	virtual ~DatosBio();
	virtual void setEstatura(double);
	virtual void setPeso(double);
	virtual void setPorcGrasaCorpo(double);
	virtual void setPorcMasaMuscu(double);

	virtual double getEstatura();
	virtual double getPeso();
	virtual double getPorcGrasaCorpo();
	virtual double getPorcMasaMuscu();

private:
	double estatura;
	double peso;
	double porcGrasaCorpo;
	double porcMasaMuscu;
};
