#include <iostream>
#include "Lista.h"
#include "Menu.h"
#include "Deportista.h"

int main()
{
    string cedula, nombre, sexo;
    int numero = 0;

    Menu menu;
    menu.mostrarOpciones();
    menu.agregarCliente(cedula,nombre,numero,sexo); // no está haciendo nada, falta el vector en el metodo
                                                    // era para ver si mostraba bien el menu


    //Deportista* persona1 = new Deportista("111", "Juan", 6064654, 'M');

    //Lista<Deportista> lista1;
    //lista1.agregar(persona1);

    //cout << lista1.toString();

    return 0;
}
