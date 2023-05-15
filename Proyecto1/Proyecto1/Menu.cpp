#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Menu::Menu() : opcion(0), deportistas(new Lista<Deportista>()), bios(NULL), G(new Lista<Gimnasio>()), gym(new Gimnasio()), grupo(NULL), curso(NULL)
{
}

Menu::~Menu()
{
}

void Menu::menuPrincipal()
{
    cout << "-----------Gimnasio-----------" << endl;
    //Listas
    cout << "\n1. Lista general de clientes."; // Listo
    cout << "\n2. Lista de clientes activos."; // no pude
    cout << "\n3. Lista de cursos disponibles."; // no pude
    cout << "\n4. Lista de cursos con sus respectivos grupos."; // no pude
    //Agregar y actualizar
    cout << "\n5. Agregar clientes."; // listo
    cout << "\n6. Actualizar clientes."; // listo
    cout << "\n7. Agregar Curso."; // listo
    cout << "\n8. Inscribirse al curso";
    cout << "\n0. Salir. \n";
}

void Menu::iniciar()
{
    string id, nombre, numero;
    char sexo;
    double estatura, peso, porcGrasaCorpo, porcMasaMuscu;
    Deportista* deportista;
    IteradorLista<Deportista>* Cl = nullptr;
    ofstream archivo("GYM.txt");

    string nombreCurso, descripcion, nivel, fechas, horario;
    int cupoMaximo;
    int numeroGrupo, capacidad, cantidadMatriculados = 0;
    IteradorLista<Gimnasio>* g = nullptr;

    int dia1 = 0, dia2 = 0, dia3 = 0, mes1 = 0, mes2 = 0, mes3 = 0, ano1 = 0, ano2 = 0, ano3 = 0;
    Fecha* fechaRegis = new Fecha(dia1, mes1, ano1);
    Fecha* fechaNacim = new Fecha(dia2, mes2, ano2);
    Fecha* fechaInicio = new Fecha(dia3, mes3, ano3);
    int siono = 1;
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

            try {
                if (Cl == nullptr) {
                    throw invalid_argument("No existe una lista de cliente aun.\n");
                }
                else if (Cl != nullptr) {

                    cout << "Lista de los Clientes registrados en el Gym." << "\n\n";
                    Cl = deportistas->obtenerIterador();
                    while (Cl->masElementos()) {
                        deportista = Cl->proximoElemento();
                        cout << deportista->toString() << "\n";
                        archivo << "Cliente.\n";
                        archivo << deportista->toString() << endl;
                    }
                    delete Cl;
                    cout << "\n";
                    system("pause");
                }
            }
            catch (exception& e) {
                cerr << "\nError: " << e.what() << endl;
                system("pause");
            }
            break;

        case 2: //Clientes activos
            system("cls");
            if (siono == 1)
            {
                cout << grupo->listaDeportistas();
            }
            system("pause");
            break;

        case 3: //Lista de cursos
            system("cls");
            cout << gym->listaCurso();
            archivo << "Curso.\n";
            archivo << gym->listaCurso() << endl;
            system("pause");
            
            break;

        case 4: //Lista de cursos con sus respectivos grupos
            system("cls");
            cout << gym->listaCursoConGrupo();
            system("pause");
            break;

        case 5: // Agregar Clientes
            
            system("cls");

            cout << "-----Fecha de registro-----" << endl;
            cout << "\nDia: ";
            cin >> dia1;
            
            while (cin.fail()) {
                try {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                    }
                }
                catch (exception& e) {
                    cerr << "\nError: " << e.what() << endl;
                    cout << "Vuelva a indicar el dia: ";
                    cin >> dia1;
                    cout << "\n";
                }

            }



            cout << "Mes: ";
            cin >> mes1;

            while (cin.fail()) {
                try {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                    }
                }
                catch (exception& e) {
                    cerr << "\nError: " << e.what() << endl;
                    cout << "Vuelva a indicar el mes: ";
                    cin >> mes1;
                    cout << "\n";
                }

            }

            cout << "Ano: ";
            cin >> ano1;
            while (cin.fail()) {
                try {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                    }
                }
                catch (exception& e) {
                    cerr << "\nError: " << e.what() << endl;
                    cout << "Vuelva a indicar el anno: ";
                    cin >> ano1;
                    cout << "\n";
                }

            }



            fechaRegis = new Fecha(dia1, mes1, ano1);
            system("cls");

            cout << "-----Informacion Personal-----" << endl;
            Cl = deportistas->obtenerIterador();
            cout << "\nCedula: ";
            cin >> id;

            while (Cl->masElementos()) {

                deportista = Cl->proximoElemento();

                while (id == deportista->getId()) {
                    try {
                        if (id == deportista->getId()) {
                            throw invalid_argument("Esta cedula ya esta registrada.");

                        }
                    }
                    catch (exception& e) {
                        cerr << "\nError: " << e.what() << endl;
                        cout << "Vuelva a intentarlo con una nueva cedula: ";
                        cin >> id;
                        cout << "\n";
                    }
                }

            }
            

            cout << "Nombre: ";
            cin >> nombre;

            cout << "Numero de telefono: ";
            cin >> numero;

            cout << "Sexo (F/M): ";
            cin >> sexo;

            while (sexo != 'F' && sexo != 'f' && sexo != 'M' && sexo != 'm') {

                try {
                    if (sexo != 'F' && sexo != 'f' && sexo != 'M' && sexo != 'm') {
                        throw invalid_argument("Genero Invalido.");
                    }
                }
                catch (exception& e) {
                    cerr << "\nError: " << e.what() << endl;
                    cout << "Vuelva a indicar su sexo (F/M): ";
                    cin >> sexo;
                }
            }

            system("cls");

            cout << "-----Fecha de Nacimiento-----\n" << endl;
            cout << "Dia: " ;
            cin >> dia2; 
            while (cin.fail()) {
                try {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                    }
                }
                catch (exception& e) {
                    cerr << "\nError: " << e.what() << endl;
                    cout << "Vuelva a indicar el dia: ";
                    cin >> dia2;
                    cout << "\n";
                }

            }

            cout << "Mes: ";
            cin >> mes2; 
            while (cin.fail()) {
                try {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                    }
                }
                catch (exception& e) {
                    cerr << "\nError: " << e.what() << endl;
                    cout << "Vuelva a indicar el mes: ";
                    cin >> mes2;
                    cout << "\n";
                }

            }


            cout << "Anno: ";
            cin >> ano2;
            while (cin.fail()) {
                try {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                    }
                }
                catch (exception& e) {
                    cerr << "\nError: " << e.what() << endl;
                    cout << "Vuelva a indicar el anno: ";
                    cin >> ano2;
                    cout << "\n";
                }

            }
            
           
            fechaNacim = new Fecha(dia2, mes2, ano2);

            system("cls");


            cout << "\n-----Datos Biometricos-----\n" << endl;
            cout << "Ingrese su estatura: ";
            cin >> estatura;


            while (cin.fail()) {
                try {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");

                    }
                }
                catch (exception& e) {
                    cerr << "\nError: " << e.what() << endl;
                    cout << "Vuelva a indicar su estatura: ";
                    cin >> estatura;
                    cout << "\n";
                }
               
            }
          


            cout << "Ingrese su peso: ";
            cin >> peso;

            while (cin.fail()) {
                try {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                    }
                }
                catch (exception& e) {
                    cerr << "\nError: " << e.what() << endl;
                    cout << "Vuelva a indicar su peso: ";
                    cin >> peso;
                    cout << "\n";
                }
               
            }
           


            cout << "Ingrese su porcentaje de grasa corporal: ";
            cin >> porcGrasaCorpo;

            while (cin.fail()) {
                try {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                    }
                }
                catch (exception& e) {
                    cerr << "\nError: " << e.what() << endl;
                    cout << "Vuelva a indicar su Porcentaje de Grasa Corporal: ";
                    cin >> porcGrasaCorpo;
                    cout << "\n";
                }
               
            }
           


            cout << "Ingrese su porcentaje de masa muscular: ";
            cin >> porcMasaMuscu;


            while (cin.fail()) {
                try {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                    }
                }
                catch (exception& e) {
                    cerr << "\nError: " << e.what() << endl;
                    cout << "Vuelva a indicar su Porcentaje de Masa Muscular: ";
                    cin >> porcMasaMuscu;
                    cout << "\n";
                }
               
            }

            bios = new DatosBio(estatura, peso, porcGrasaCorpo, porcMasaMuscu);
            deportista = new Deportista(fechaRegis, id, nombre, numero, sexo, fechaNacim, bios);
            deportistas->agregar(deportista);

            system("cls");
            cout << "\n------Cliente registrado con exito.------\n\n";
            system("pause");

            break;


    case 6: //Actualizar cliente

        system("cls");
        Cl = deportistas->obtenerIterador();

        while (Cl->masElementos())
        {
            deportista = Cl->proximoElemento();

            cout << "\nDigite el ID del cliente: ";
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

                cout << "Digite su nueva fecha de nacimiento" << endl;
                cout << "Dia: ";
                cin >> dia2;
                cout << "Mes: ";
                cin >> mes2;
                cout << "Anno: ";
                cin >> ano2;
                fechaNacim->setDia(dia2);
                fechaNacim->setMes(mes2);
                fechaNacim->setAnno(ano2);

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
                break;
            }
        }
        delete Cl;
        system("pause");
        break;

        case 7: //agregar curso
            system("cls");

            do
            {
                system("cls");
                cout << "Agregar curso.\n" << endl;
                cout << "\nNombre del curso: ";
                cin >> nombreCurso;

                cout << "\nDescripcion del Curso: ";
                cin >> descripcion;

                cout  << "\nNivel de Curso" << "\nBasico / Medio/ Alto: ";
                cin >> nivel;

                cout << "\nFecha de inicio" << endl;
                cout << "Dia: ";
                cin >> dia3;
                while (cin.fail()) {
                    try {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(100, '\n');
                            throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                        }
                    }
                    catch (exception& e) {
                        cerr << "\nError: " << e.what() << endl;
                        cout << "Vuelva a indicar el dia: ";
                        cin >> dia3;
                        cout << "\n";
                    }

                }
                cout << "Mes: ";
                cin >> mes3;
                while (cin.fail()) {
                    try {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(100, '\n');
                            throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                        }
                    }
                    catch (exception& e) {
                        cerr << "\nError: " << e.what() << endl;
                        cout << "Vuelva a indicar el mes: ";
                        cin >> mes3;
                        cout << "\n";
                    }

                }
                cout << "Anno: ";
                cin >> ano3;
                while (cin.fail()) {
                    try {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(100, '\n');
                            throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                        }
                    }
                    catch (exception& e) {
                        cerr << "\nError: " << e.what() << endl;
                        cout << "Vuelva a indicar el anno: ";
                        cin >> ano3;
                        cout << "\n";
                    }

                }

                cout << "\nHorario del curso:" ;
                cin >> horario;

                cout << "\nCupo maximo de grupos: ";
                cin >> cupoMaximo;
                while (cin.fail()) {
                    try {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(100, '\n');
                            throw invalid_argument("Entrada invalida, ingrese solo numeros.\n");
                        }
                    }
                    catch (exception& e) {
                        cerr << "\nError: " << e.what() << endl;
                        cout << "Vuelva a indicar el cupo maximo: ";
                        cin >> cupoMaximo;
                        cout << "\n";
                    }

                }
                cout << endl;

                fechaInicio = new Fecha(dia3, mes3, ano3);
                curso = new Curso(nombreCurso, descripcion, nivel, fechaInicio, horario, cupoMaximo);

                do {
                    cout << "\nAgregar Grupo\n" << endl;
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

        case 8: //inscribirse al curso
            system("cls");
            cout << "Inscribirse a un grupo" << endl;
            cout << "\nLista de cursos" << endl;
            cout << gym->listaCurso();

            do
            {
                cout << "\nIngrese el nombre del curso al que desea inscribirse: ";
                cin >> nombreCurso;

                if (nombreCurso == curso->getNombreCurso())
                {
                    cout << gym->listaCursoConGrupo();
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

                                if (fechaInicio->dif2(fechaRegis) >= 0)
                                {
                                    cout << "\nFaltan: " << fechaInicio->dif2(fechaRegis) << " dias para que inicie el curso";
                                    cout << "\nEl costo del curso es de $20, Desea matricularse? 1.SI | 2.NO: ";
                                    cin >> siono;
                                    if (siono == 1)
                                    {
                                        grupo->agregarDepor(deportista);
                                        grupo->incrementarCantidadMatriculados();
                                        cout << "Cliente matriculado con exito." << endl;
                                        break;
                                    }
                                }
                                else
                                {
                                    cout << "Ya es tarde tarde para matricular";
                                    system("pause");
                                    break;
                                }
                            }
                        }
                    }
                }
                cout << "\nLista de clientes inscritos";
                cout << grupo->listaDeportistas();

                cout << "¿Desea inscribirse a otro curso? Digite 1.Si o 2.No: ";
                cin >> continuar3;

            } while (continuar3 == 1);
            system("pause");
            break;

        case 0:
            system("cls");
            cout << "Saliendo del programa." << endl;
            system("pause");

            break;
        default:
            system("cls");
            cout << "Opcion invalida. Intente nuevamente." << endl;
            system("pause");
            break;
        }
        cout << endl;
    } while (opcion != 0);

    archivo.close();
    delete gym;
    delete curso;
    delete grupo;
}