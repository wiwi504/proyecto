#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

Menu::Menu() : opcion(0), deportistas(new Lista<Deportista>())/*, bios(new DatosBio())*/ /*inicializar bien DatosBio*/ , gym(new Gimnasio())
{
}

Menu::~Menu()
{
}

void Menu::menuPrincipal()
{
    cout << "Gimnasio" << endl;
    //Listas
    cout << "\n1. Lista general de clientes.";
    cout << "\n2. Lista de clientes activos.";
    cout << "\n3. Lista de cursos disponibles.";
    cout << "\n4. Lista de cursos con sus respectivos grupos.";
    cout << "\n5. Lista de grupos (clientes que han hecho reservas).";
    //Agregar y actualizar
    cout << "\n6. Agregar clientes.";
    cout << "\n7. Actualizar clientes.";
    cout << "\n8. Agregar Curso.";
    cout << "\n8. Agregar grupo.";
    cout << "\n0. Salir.";
    cout << "\n";
}

void Menu::iniciar()
{
    string id, nombre, numero;
    char sexo;
    double estatura, peso, porcGrasaCorpo, porcMasaMuscu;
    Deportista* deportista;
    DatosBio* datosBio;
    IteradorLista<Deportista>* Cl;

    string nombreCurso, descripcion, nivel, fechas, horario;
    int cupoMaximo;
    Curso* curso;
    
    int numero, capacidad, cantidadMatrulados;
    Grupo* grupo;

    do 
    {
        system("cls");
        menuPrincipal();
        cout << "\nDigite una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1: //Lista Clientes
            system("cls");
            Cl = deportistas->obtenerIterador();
            while (Cl->masElementos()) {
                deportista = Cl->proximoElemento();
                cout << "\n" << deportista->toString();
            }
            delete Cl;
            system("pause");
            break;

        case 2:
            break;

        case 3: //Lista de cursos
            system("cls");
            cout << gym->listaCurso();
            system("pause");
            break;

        case 4: //Lista de cursos con sus respectivos grupos
            system("cls");
            cout << gym->listaCursoConGrupo(); 
            system("pause");
            break;

        case 5: //Lista de grupos
            system("cls");

            system("pause");
            break;

        case 6: // Agregar Clientes
            system("cls");
            cout << "Información Personal" << endl;
            cout << "Cedula: ";
            cin >> id;

            cout << "Nombre: ";
            cin >> nombre;

            cout << "Numero de telefono: ";
            cin >> numero;

            cout << "Sexo (F o M): ";
            cin >> sexo;

            cout << "Datos Biometricos" << endl;
            cout << "Ingrese su estatura: ";
            cin >> estatura;

            cout << "Ingrese su peso: ";
            cin >> peso;

            cout << "Ingrese su porcentaje de grasa corporal: ";
            cin >> porcGrasaCorpo;

            cout << "Ingrese su porcentaje de masa muscular: ";
            cin >> porcMasaMuscu;

            datosBio = new DatosBio(estatura, peso, porcGrasaCorpo, porcMasaMuscu);
            deportista = new Deportista(id, nombre, numero, sexo, datosBio);
            deportistas->agregar(deportista);

            cout << "\nCliente registrado con exito." << endl;
            system("pause");

            break;

        case 7: //Actualizar cliente
            system("cls");
            Cl = deportistas->obtenerIterador();

            while (Cl->masElementos())
            {
                deportista = Cl->proximoElemento();

                cout << "\nDigite el id del cliente: ";
                cin >> id;

                if (id == deportista->getId()) {
                    cout << "\n" << deportista->toString();

                    cout << "\nDigite el nuevo nombre: ";
                    cin >> nombre;
                    deportista->setNombre(nombre);

                    cout << "\nDigite el nuevo telefono: ";
                    cin >> numero;
                    deportista->setTelefono(numero);

                    cout << "Digite el nuevo genero (F o M): ";
                    cin >> sexo;
                    deportista->setSexo(sexo);

                    cout << "Ingrese su nueva estatura: ";
                    cin >> estatura;
                    datosBio->setEstatura(estatura);

                    cout << "Ingrese su nuevo peso: ";
                    cin >> peso;
                    datosBio->setPeso(peso);

                    cout << "Ingrese su nuevo porcentaje de grasa corporal: ";
                    cin >> porcGrasaCorpo;
                    datosBio->setPorcGrasaCorpo(porcGrasaCorpo);
                
                    cout << "Ingrese su nuevo porcentaje de masa muscular: ";
                    cin >> porcMasaMuscu;
                    datosBio->setPorcMasaMuscu(porcMasaMuscu);

                    cout << "\nCliente actualizado exitosamente.";
                    system("pause");
                    break;
                }
            }

        case 8: //agregar curso
            system("cls");
            cout << "\nNombre del curso: ";
            cin >> nombreCurso;
            
            cout << "\nDescripcion del Curso: ";
            cin >> descripcion;

            cout << "\nNivel de Curso: ";
            cin >> nivel;

            cout << "\nFecha de inicio: ";
            cin >> fechas;

            cout << "\nHorario del curso: ";
            cin >> horario;

            cout << "\nCupo maximo: ";
            cin >> cupoMaximo;

            cout << "Lista de clientes incritos: ";
            //no sé cómo hacer eso

            curso = new Curso(nombreCurso, descripcion, nivel, fechas, horario, cupoMaximo);
            gym->agregarCurso(curso);

            cout << "Curso agregado correctamente." << endl;
            system("pause");

            break;

        case 9: //agregar de grupos
            system("cls");
            cout << "Ingrese el numero del grupo: ";
            cin >> numero;

            cout << "Ingrese la cantidad de deportistas que tendra dicho grupo: ";
            cin >> capacidad;

            cout << "Grupo registrado correctamente";
            system("pause");
            break;

        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            system("pause");
            break;
        }
        cout << endl;
    } while (opcion != 0);
}