#pragma once
#include "Grupo.h"
#include "ObjetoBase.h"
#include "Lista.h"
#include <string>
using std::string;

class Curso : public ObjetoBase
{
public:
	Curso(string, string, string, string, string, int);
	virtual ~Curso();
	virtual string getNombreCurso() const;
	virtual string getDescripcion() const;
	virtual string getNivel() const;
	virtual string getFechas() const;
	virtual string getHorario() const;
	virtual int getCupoMaximo() const;
	virtual void agregarGrupo(Grupo*);
	virtual string toString() const;
	virtual string toStringConGrupo() const;

private:
	string nombreCurso;
	string descripcion;
	string nivel;
	string fechas;
	string horario;
	int cupoMaximo;
	Lista<Grupo>* grupos;
	
};


