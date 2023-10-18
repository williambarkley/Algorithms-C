#include "Agenda1.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

Agenda::Agenda(int capacidad)
{
    this->capacidad = capacidad;
    telefonos = new long[capacidad];
    nombres = new string[capacidad];
    ocupados = new bool[capacidad];
}
int Agenda::obtenerPosicion(long telefono)
{
    return (telefono%capacidad);
}
bool Agenda::existeContacto(long telefono)
{
    if(ocupados[obtenerPosicion(telefono)])
    {
        if (telefonos[obtenerPosicion(telefono)] == telefono)
        {
            return true;
        }
    }

        return false;
}
string Agenda::getContacto(long telefono)
{
    assertdomjudge(existeContacto(telefono))
    return nombres[obtenerPosicion(telefono)];
}
void Agenda::introducirContacto(long telefono, string contacto)
{
    assertdomjudge(ocupados[obtenerPosicion(telefono)] != true)
    nombres[obtenerPosicion(telefono)] = contacto;
    telefonos[obtenerPosicion(telefono)] = telefono;
    ocupados[obtenerPosicion(telefono)] = true;
}
void Agenda::eliminarContacto(long telefono)
{
    assertdomjudge(existeContacto(telefono))
    ocupados[obtenerPosicion(telefono)] = false;
}
void Agenda::imprimir()
{
    for (int i=0; i<capacidad; i++)
        cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

Agenda::~Agenda()
{
    delete[] telefonos;
    delete[] nombres;
    delete[] ocupados;
}






