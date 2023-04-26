#pragma once

template <class T>
class Nodo
{
public:
	Nodo(T*, Nodo<T>*);
	virtual ~Nodo();
	virtual T* getDato();
	virtual Nodo<T>* getSiguiente();
private:
	T* dato;
	Nodo<T>* siguiente;
};

template <class T>
Nodo<T>::Nodo(T* dato, Nodo<T>* siguiente)
	: dato(dato), siguiente(siguiente) {

}

template <class T>
Nodo<T>::~Nodo() {

}

template <class T>
T* Nodo<T>::getDato() {
	return dato;
}

template <class T>
Nodo<T>* Nodo<T>::getSiguiente() {
	return siguiente;
}
