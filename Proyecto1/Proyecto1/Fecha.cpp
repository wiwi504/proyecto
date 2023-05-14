#include "Fecha.h"
#include <sstream>
using std::stringstream;


Fecha::Fecha(int dia, int mes, int anno) : dia(dia), mes(mes), anno(anno)
{
}

Fecha::~Fecha()
{
}

void Fecha::setDia(int dia)
{
    this->dia = dia;
}

void Fecha::setMes(int mes)
{
    this->mes = mes;
}

void Fecha::setAnno(int anno)
{
    this->anno = anno;
}

int Fecha::getDia()
{
    return this->dia;
}

int Fecha::getMes()
{
    return this->mes;
}

int Fecha::getAnno()
{
    return this->anno;
}

string Fecha::FechaActual()
{
    stringstream r;
    time_t tiempoActual = time(0);

    tm tiempoLocal;
    localtime_s(&tiempoLocal, &tiempoActual);

    r << tiempoLocal.tm_mday << "/" << tiempoLocal.tm_mon + 1 << "/" << tiempoLocal.tm_year + 1900 << endl;

    return r.str();
}

int Fecha::difFecha() {

    time_t tiempo_actual;
    time(&tiempo_actual);
    tm tiempo_local;
    localtime_s(&tiempo_local, &tiempo_actual);


    int fecha = tiempo_local.tm_year + 1900 - anno;
    if (mes > tiempo_local.tm_mon + 1 || (mes == tiempo_local.tm_mon + 1 && dia > tiempo_local.tm_mday)) {
        fecha--;
    }
    return fecha;
}

string Fecha::toString()
{
    stringstream x;
    x << dia << " - " << mes << " - " << anno;
    return x.str();
}

int Fecha::dif2(Fecha* regis) const
{
    const int DIAS_POR_MES[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int dias = dia - regis->getDia();
    int meses = mes - regis->getMes();
    int anios = anno - regis->getAnno();
    int diasTotales = 0;

    for (int i = 0; i < abs(meses); ++i) {
        int diasEnMes = DIAS_POR_MES[(mes - i - 1 + 12) % 12];
        diasTotales += diasEnMes;
    }

    diasTotales += anios * 365;
    diasTotales += dias;

    return diasTotales;
}