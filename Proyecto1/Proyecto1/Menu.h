#pragma once
#include <string>

using namespace std;

class Menu

{
public: // S�lo se est� enfocando en mostrarOpciones (no hace nada) y mostrarClientes (solo ense�a texto). Los dem�s m�todos est�n vac�os.

	void mostrarOpciones();

	void agregarCliente(string,string,int,string); // c�dula, nombre, celular y sexo (jeje)
	void mostrarClientes();

	void desactivarCliente(string);

	void agregarCurso(string); // nombreCurso

	void agregarGrupo(string,int); // nombreCurso y numGrupo

private: // de momento, no hay atributos que poner ya que los temporales se eliminaron.

};

