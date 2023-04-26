#pragma once

#include <string>
#include <sstream>
using namespace std;

#include "Nodo.h"

template <class T> // class o typename
class Lista
{
public:
	Lista();
	virtual ~Lista();
	virtual void agregar(T*);
	virtual string toString();
private:
	Nodo<T>* primero;
	Nodo<T>* actual;
};

template <class T>
Lista<T>::Lista() : primero(NULL), actual(NULL) {

}

template <class T>
Lista<T>::~Lista() {

}

template <class T>
void Lista<T>::agregar(T* dato) {
	primero = new Nodo<T>(dato, primero);
}

template <class T>
string Lista<T>::toString() {
	stringstream r;
	actual = primero;
	T* dato;
	while (actual != NULL) {
		dato = actual->getDato();
		r << *dato;
		actual = actual->getSiguiente();
		r << "\n";
	}
	return r.str();
}
