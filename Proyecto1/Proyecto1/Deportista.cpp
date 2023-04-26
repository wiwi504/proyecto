#include "Deportista.h"
#include <sstream>

//Tira un error que no entiendo desde antes que implementara los métodos acá.

Deportista::Deportista(string id, string nombre, int telefono, char s) : id(id), nombre(nombre), telefono(telefono), sexo(s)
{
}

Deportista::~Deportista()
{
}

string Deportista::getId()
{
	return id;
}

void Deportista::setId(string id)
{
	id = id;
}

string Deportista::getNombre()
{
	return nombre;
}

void Deportista::setNombre(string nom)
{
	nombre = nom;
}

int Deportista::getTelefono()
{
	return telefono;
}

void Deportista::setTelefono(int tel)
{
	telefono = tel;
}

char Deportista::getSexo()
{
	return sexo;
}

void Deportista::setSexo(char s)
{
	sexo = s;
}

string Deportista::toString() const
{
	stringstream r;
	r << "Nombre: " << nombre << endl;
	r << "ID: " << id << endl;
	r << "Telefono: " << telefono << endl;
	r << "Sexo: " << sexo << endl;

	return r.str();

	
}
