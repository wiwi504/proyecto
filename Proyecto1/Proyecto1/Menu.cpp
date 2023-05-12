#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

Menu::Menu() : opcion(0), deportistas(new Lista<Deportista>()), bios(NULL), G(new Lista<Gimnasio>()), gym(new Gimnasio()), grupo(NULL), curso(NULL)
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
    cout << "\n5. Lista de grupos.";
    //Agregar y actualizar
    cout << "\n6. Agregar clientes.";
    cout << "\n7. Actualizar clientes.";
    cout << "\n8. Agregar Curso.";
    cout << "\n9. Inscribirse al curso";
    cout << "\n0. Salir.";
    cout << "\n";
}

void Menu::iniciar()
{
    string id, nombre, numero;
    char sexo;
    double estatura, peso, porcGrasaCorpo, porcMasaMuscu;
    Deportista* deportista;
    IteradorLista<Deportista>* Cl;

    string nombreCurso, descripcion, nivel, fechas, horario;
    int cupoMaximo;
    //Curso* curso;
    //IteradorLista<Curso>* LisCur;
    int numeroGrupo, capacidad;
    //Grupo* grupo;
    //IteradorLista<Grupo>* g;

    //Gimnasio* gym;
    IteradorLista<Gimnasio>* g;

    int continuar1 = 1;
    int continuar2 = 1;
    int continuar3 = 1;

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
            //cout << "\n" << curso->toString();
            system("pause");
            break;

        case 6: // Agregar Clientes
            system("cls");
            cout << "Informacion Personal" << endl;
            cout << "Cedula: ";
            cin >> id;

            cout << "Nombre: ";
            cin >> nombre;

            cout << "Numero de telefono: ";
            cin >> numero;

            cout << "Sexo (F o M): ";
            cin >> sexo;

            cout << "\nDatos Biometricos" << endl;
            cout << "Ingrese su estatura: ";
            cin >> estatura;

            cout << "Ingrese su peso: ";
            cin >> peso;

            cout << "Ingrese su porcentaje de grasa corporal: ";
            cin >> porcGrasaCorpo;

            cout << "Ingrese su porcentaje de masa muscular: ";
            cin >> porcMasaMuscu;

            bios = new DatosBio(estatura, peso, porcGrasaCorpo, porcMasaMuscu);
            deportista = new Deportista(id, nombre, numero, sexo, bios);
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
                    bios->setEstatura(estatura);

                    cout << "Ingrese su nuevo peso: ";
                    cin >> peso;
                    bios->setPeso(peso);

                    cout << "Ingrese su nuevo porcentaje de grasa corporal: ";
                    cin >> porcGrasaCorpo;
                    bios->setPorcGrasaCorpo(porcGrasaCorpo);
                
                    cout << "Ingrese su nuevo porcentaje de masa muscular: ";
                    cin >> porcMasaMuscu;
                    bios->setPorcMasaMuscu(porcMasaMuscu);

                    cout << "\nCliente actualizado exitosamente.";
                    system("pause");
                    
                }
            }
            break;

        case 8: //agregar curso
            system("cls");
            
            do
            {
                system("cls");
                cout << "Agregar curso" << endl;
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
                cout << endl;

                curso = new Curso(nombreCurso, descripcion, nivel, fechas, horario, cupoMaximo);

                do {
                    cout << "\nAgregar Grupo" << endl;
                    cout << "Ingrese el numero del grupo: ";
                    cin >> numeroGrupo;

                    cout << "Ingrese la cantidad de deportistas que tendra dicho grupo: ";
                    cin >> capacidad;

                    grupo = new Grupo(numeroGrupo, capacidad);
                    curso->agregarGrupo(grupo);


                    cout << "\nDesea agregar otro grupo. Digite 1.Si o 2.No: ";
                    cin >> continuar1;

                } while (continuar1 == 1);

                gym->agregarCurso(curso);

                cout << "\nDesea agregar otro curso. Digite 1.Si o 2.No: ";
                cin >> continuar2;

            } while (continuar2 == 1);

            cout << "Curso agregado correctamente." << endl;
            system("pause");

            break;

        case 9: //inscribirse al curso
            system("cls");
            cout << "Inscribirse a un grupo" << endl;
            cout << "\nLista de cursos" << endl;
            cout << gym->listaCurso();

            do
            {
               /* g = G->obtenerIterador();
                while (g->masElementos())
                {
                    gym = g->proximoElemento();*/
                    cout << "\nIngrese el nombre del curso al que desea inscribirse: ";
                    cin >> nombreCurso;

                    if (nombreCurso == curso->getNombreCurso())
                    {
                        cout << gym->listaCursoConGrupo();
                       /* g = G->obtenerIterador();
                        while (g->masElementos())
                        {
                            gym = g->proximoElemento();*/
                            cout << "\nIngrese el numero del grupo al que desea ingresar: ";
                            cin >> numeroGrupo;

                            if (numeroGrupo == grupo->getNumero())
                            {
                                cout << grupo->toString();
                                Cl = deportistas->obtenerIterador();
                                while (Cl->masElementos())
                                {
                                    deportista = Cl->proximoElemento();
                                    cout << "\nDigite su id: ";
                                    cin >> id;

                                    if (id == deportista->getId())
                                    {
                                        cout << "\n" << deportista->toString();
                                        deportistas->agregar(deportista);
                                    }
                                }
                            }
                        //}
                    }
                //}
                /*cout << "\nLista de clientes incritos: ";*/
                //no sé cómo hacer eso
                cout << "¿Desea inscribirse a otro curso? Digite 1.Si o 2.No: ";
                cin >> continuar3;

            } while (continuar3 == 1);
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
    delete gym;
    delete curso;
    delete grupo;
}