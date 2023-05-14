#include "Deportista.h"
#include <sstream>
using std::stringstream;

Deportista::Deportista(Fecha* fechaRegistro, string id, string nombre, string telefono, char s, Fecha* fechaNacim, DatosBio* datosBio) : fechaRegistro(fechaRegistro), id(id), nombre(nombre), telefono(telefono), sexo(s), fechaNacim(fechaNacim), datosBio(datosBio)
{
}

Deportista::~Deportista()
{
}

void Deportista::setId(string id)
{
	this->id = id;
}

void Deportista::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Deportista::setTelefono(string telefono)
{
	this->telefono = telefono;
}

void Deportista::setSexo(char sexo)
{
	this->sexo = sexo;
}

string Deportista::getId()
{
	return this->id;
}

string Deportista::getNombre()
{
	return this->nombre;
}

string Deportista::getTelefono()
{
	return this->telefono;
}

char Deportista::getsexo()
{
	return this->sexo;
}

string Deportista::toString() const
{
	stringstream r;
	r << "\nFecha de registro: " << fechaRegistro->toString() << endl;
	r << "Nombre: " << nombre << endl;
	r << "ID: " << id << endl;
	r << "Telefono: " << telefono << endl;
	r << "Sexo: " << sexo << endl;
	r << "Fecha de cumpleannos: " << fechaNacim->toString() << endl;
	r << "Edad: " << fechaNacim->difFecha() << endl;

	return r.str();
}
