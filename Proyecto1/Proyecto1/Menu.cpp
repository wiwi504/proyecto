#include "Menu.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Menu::Menu() : d1("NoId", "SinNombre", 0, 'I') {

}

Menu::~Menu()
{
}

void Menu::mostrar() {

    int opcion;

    //Deportista
    string id;
    string nombre;
    int telefono;
    char sexo;

    do {
        cout << "1. Crear persona" << endl;
        cout << "2. Deportista Ingresado" << endl;
        cout << "3. Salir" << "\n\n";

        cout << "Ingrese su opcion: ";
        cin >> opcion;

        system("cls");

        switch (opcion) {
        case 1:

            cout << "ingrese el id: ";
            cin >> id;
            cout << "ingrese el nombre: ";
            cin >> nombre;
            cout << "ingrese el telefono: ";
            cin >> telefono;
            cout << "ingrese el sexo: ";
            cin >> sexo;
            d1 = Deportista(id, nombre, telefono, sexo);

            cout << "\n"; // Es solo para orden a la hora de compilar
            //system("pause");
            system("cls");


            cout << "Se ha creado el deportista exitosamente.\n\n";

            system("pause");
            system("cls");

            break;

        case 2:

            cout << "Deportista\n\n";
            cout << d1.toString() << "\n\n";

            system("pause");
            system("cls");

            break;
        case 3:

            cout << "Saliendo del programa." << endl;

            system("pause");
            system("cls");
            break;

        default:
            cout << "Opcion no valida vuelva a intentarlo." << "\n";

            system("pause");
            system("cls");

            break;
        }


    } while (opcion != 0);



}






//void Menu::mostrarOpciones()
//{
//    int opcion;
//    do {
//
//        string cedula, nombre, sexo;
//        int numero = 0;
//
//        system("cls");
//
//        cout << "Bienvenido al gimnasio de Kristel de Triatlonistas Corredores Extremos." << endl;
//        cout << "\n1. Lista general de clientes" << endl;
//        cout << "2. Lista de clientes activos" << endl;
//        cout << "3. Lista de cursos disponibles" << endl;
//        cout << "4. Lista de cursos con sus respectivos grupos" << endl;
//        cout << "5. Lista de grupos (clientes que han hecho reservas)" << endl;
//        cout << "6. Agregar clientes" << endl;
//        cout << "0. Salir" << endl;
//        cout << "\n";
//        cout << "Seleccione una opcion: ";
//        cin >> opcion;
//
//        switch (opcion) {
//        case 1:
//            mostrarClientes();
//            break;
//
//        case 2:
//            break;
//
//        case 3:
//            break;
//
//        case 4:
//            break;
//
//        case 5:
//            break;
//        
//        case 6:
//
//            system("cls");
//            agregarCliente(cedula,nombre,numero,sexo);
//            system("pause");
//
//             break;
//
//        case 0:
//            cout << "Saliendo del programa." << endl;
//            break;
//        default:
//            cout << "Opcion invalida. Intente nuevamente." << endl;
//            system("pause");
//            break;
//        }
//        cout << endl;
//    } while (opcion != 0);
//}
//
//void Menu::mostrarClientes() {
//
//    cout << "Lista general de clientes:" << endl;
//    cout << "La lista esta vacia." << endl;
//
//}
//
//void Menu::agregarCliente(string id, string nombre, int numero, string sexo) {
//
//    cout << "Inserte su cedula: ";
//    cin >> id;
//
//    cout << "Inserte su nombre: ";
//    cin >> nombre;
//
//    cout << "Numero de telefono: ";
//    cin >> numero;
//
//    cout << "Hombre o Mujer? (No hay mas generos) (H o M): ";
//    cin >> sexo;
//
//    cout << "\n";
//
//    // falta hacer un for en el que se registre en el almacen generico
//    // los clientes.
//
//    cout << "Cliente registrado con exito." << endl;
//    cout << "\n";
//
//}
