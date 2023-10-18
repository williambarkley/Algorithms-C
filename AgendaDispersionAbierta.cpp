#include "Agenda.h"
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include "impresionListasEnlazadas.h" // Para el método imprimir de la tabla hash

using namespace std;

Agenda::Agenda(int capacidad)
{
    this->capacidad = capacidad;
    tabla = new ListaEnlazada[capacidad];
}
int Agenda::obtenerPosicion(long telefono)
{
    return (telefono%capacidad);
}
bool Agenda::existeContacto(long telefono)
{
    Contacto * contacto = new Contacto();
    contacto->telefono=telefono;
    if(tabla[obtenerPosicion(telefono)].buscar(*contacto) != -1)
    {
        return true;
    }

    return false;
}
string Agenda::getContacto(long telefono)
{
    assertdomjudge(existeContacto(telefono))
    Contacto * contacto = new Contacto();
    contacto->telefono = telefono;
    *contacto = tabla[obtenerPosicion(telefono)].getValor(tabla[obtenerPosicion(telefono)].buscar(*contacto));
    return contacto->nombre;
}

void Agenda::introducirContacto(long telefono,string nombre)
{
    assertdomjudge(!existeContacto(telefono))
    Contacto * contacto = new Contacto();
    contacto->nombre = nombre;
    contacto->telefono = telefono;
    tabla[obtenerPosicion(telefono)].insertar(0,*contacto);
    n++;
}

void Agenda::eliminarContacto(long telefono)
{
    assertdomjudge(existeContacto(telefono))
    Contacto * contacto = new Contacto();
    contacto->telefono = telefono;
    tabla[obtenerPosicion(telefono)].eliminar(tabla[obtenerPosicion(telefono)].buscar(*contacto));
    n--;
}

void Agenda::imprimir()
{
	for (int i=0; i<capacidad; i++) {
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&tabla[i]);
	}
}
Agenda::~Agenda()
{
    delete[] tabla;
}

