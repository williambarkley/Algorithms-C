#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#include "ListaEnlazada.h"
#include <iostream>

Nodo * ListaEnlazada::getNodo(int posicion)
{
    Nodo * nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo = lista;
    for(int i = 0;i<posicion;i++)
    {
        nodo = nodo->siguienteNodo;
    }
    return nodo;
}

ListaEnlazada::ListaEnlazada()
{
    n = 0;
    lista = NULL;
}

Contacto ListaEnlazada::getValor(int posicion)
{
    assertdomjudge(posicion < n && posicion >= 0);
    Nodo * nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo = getNodo(posicion);
    return nodo->elemento;
}

void ListaEnlazada::setValor(int posicion, Contacto nuevoValor)
{
    assertdomjudge(posicion < n && n > 0 && posicion >= 0);
    Nodo * nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo = getNodo(posicion);
    nodo->elemento = nuevoValor;
}

int ListaEnlazada::getN()
{
    return n;
}

void ListaEnlazada::insertar(int posicion, Contacto nuevoValor)
{
    assertdomjudge(posicion <= n && posicion >= 0);

    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    Nodo * anterior= (Nodo *)malloc(sizeof(Nodo));
    Nodo *siguiente = (Nodo *)malloc(sizeof(Nodo));
    Nodo *ultimo = (Nodo *)malloc(sizeof(Nodo));


    if (posicion == 0)
    {
        if (n == 0)
        {
            lista = (Nodo *)malloc(sizeof(Nodo));
            lista->elemento = nuevoValor;
        }
        else
        {
            siguiente->elemento = lista->elemento;
            siguiente->siguienteNodo = lista->siguienteNodo;
            lista->elemento = nuevoValor;
            lista->siguienteNodo = siguiente;
        }
    }
    else if (posicion > 0)
    {
        anterior = getNodo(posicion - 1);
        siguiente = getNodo(posicion);
        nodo->elemento = nuevoValor;
        nodo->siguienteNodo = siguiente;
        anterior->siguienteNodo = nodo;
    }

    else if (n > 0 && posicion == n)
    {
        ultimo = getNodo(posicion - 1);
        nodo->elemento = nuevoValor;
        ultimo->siguienteNodo = nodo;
    }
    n++;
}

void ListaEnlazada::eliminar(int posicion)
{
    assertdomjudge(n > 0 && posicion < n && posicion >= 0);

    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    Nodo *anterior = (Nodo *)malloc(sizeof(Nodo));


    if (posicion == 0)
    {
        if (n == 1)
        {
            free(lista);
            lista = NULL;
        }
        else
        {
            free(lista);
            lista = getNodo(posicion + 1);
        }
    }
    else if (posicion > 0)
    {
        nodo = getNodo(posicion);
        anterior = getNodo(posicion - 1);
        anterior->siguienteNodo = anterior->siguienteNodo->siguienteNodo;
        nodo = NULL;
        free(nodo);
    }
    else if (n > 0 && posicion == n)
    {
        nodo = getNodo(posicion);
        anterior = getNodo(posicion - 1);
        anterior->siguienteNodo = NULL;
        nodo = NULL;
        free(nodo);
    }
    n--;
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar)
{
    int j = listaAConcatenar->getN();

    for (int i = 0; i < j; i++)
    {
        insertar(n, listaAConcatenar->getValor(i));
    }
}

int ListaEnlazada::buscar(Contacto elementoABuscar)
{
    int posicion = -1;
    for (int i = 0; i < n; i++)
    {
        if (getValor(i).telefono == elementoABuscar.telefono)
        {
            posicion = i;
        }
    }
    return posicion;
}

ListaEnlazada::~ListaEnlazada()
{

    free(lista);
}