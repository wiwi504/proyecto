#include <iostream>
#include "Menu.h"

int main()
{
    Menu* m = new Menu();
    m->iniciar();
    delete m;
    return 0;
}