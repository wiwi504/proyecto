#include <iostream>
#include "Menu.h"

int main()
{
    Menu* m = new Menu();
    m->iniciar();
    delete m;
    return 0;
}

//todas las pruebas que vaya a hacer le pone su nombre y hágalas en menu
//la clase menu la arreglé acorde a la plantilla interfaz de la profe
//no pude inicializar datosbio en menu.cpp
//ya agregué iterador a la lista
//la clase gimnasio, curso y grupo lo estab intentando con el laboratorio universidad del año pasado