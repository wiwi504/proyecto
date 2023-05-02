#include "DatosBio.h"

DatosBio::DatosBio(double estatura, double peso, double porcGrasaCorpo, double porcMasaMuscu) : estatura(estatura), peso(peso), porcGrasaCorpo(porcGrasaCorpo), porcMasaMuscu(porcMasaMuscu)
{
}

DatosBio::~DatosBio()
{
}

void DatosBio::setEstatura(double estatura)
{
	this->estatura = estatura;
}

void DatosBio::setPeso(double peso)
{
	this->peso = peso;
}

void DatosBio::setPorcGrasaCorpo(double porcGrasaCorpo)
{
	this->porcGrasaCorpo = porcGrasaCorpo;
}

void DatosBio::setPorcMasaMuscu(double porcMasaMuscu)
{
	this->porcMasaMuscu = porcMasaMuscu;
}

double DatosBio::getEstatura()
{
	return this->estatura;
}

double DatosBio::getPeso()
{
	return this->peso;
}

double DatosBio::getPorcGrasaCorpo()
{
	return this->porcGrasaCorpo;
}

double DatosBio::getPorcMasaMuscu()
{
	return this->porcMasaMuscu;
}
