#pragma once
#include <string>

using namespace std;

class Menu

{
public: // Sólo se está enfocando en mostrarOpciones (no hace nada) y mostrarClientes (solo enseña texto). Los demás métodos están vacíos.

	void mostrarOpciones();

	void agregarCliente(string,string,int,string); // cédula, nombre, celular y sexo (jeje)
	void mostrarClientes();

	void desactivarCliente(string);

	void agregarCurso(string); // nombreCurso

	void agregarGrupo(string,int); // nombreCurso y numGrupo

private: // de momento, no hay atributos que poner ya que los temporales se eliminaron.

};

