// Proyecto1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Lista.h"
#include "Deportista.h"

int main()
{

    Deportista* persona1 = new Deportista("111", "Juan", 6064654, 'M');

    Lista<Deportista> lista1;
    lista1.agregar(persona1);

    cout << lista1.toString();

}
