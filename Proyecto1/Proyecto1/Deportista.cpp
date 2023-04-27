#include "Deportista.h"
#include <sstream>
using std::stringstream;

Deportista::Deportista(string id, string nombre, int telefono, char s) : id(id), nombre(nombre), telefono(telefono), sexo(s)
{
}

Deportista::~Deportista()
{
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
