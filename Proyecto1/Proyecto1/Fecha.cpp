#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int anno) : dia(dia), mes(mes), anno(anno)
{
}

Fecha::~Fecha()
{
}

int Fecha::difFecha(const Fecha& fechaInicio) const
{
	int fecha = abs(anno - fechaInicio.anno);
    if (fecha == 0) {
      if (mes < fechaInicio.mes) {
        fecha++;
           } else if (mes == fechaInicio.mes) {
        if (dia < fechaInicio.dia) {
          fecha++;
        }
      }
    }
    else {
        if (mes < fechaInicio.mes) {
            fecha--;
        } else if (mes == fechaInicio.mes) {
            if (dia < fechaInicio.dia) {
                fecha--;
            }
        }
    }
    return fecha;
}

int Fecha::edad(const Fecha& fechaNacim) const
{
	return difFecha(fechaNacim);
}
