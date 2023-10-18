#pragma once
#include "Nodo.h"

// �rbol binario de b�squeda.
class ABB
{
    Nodo *raiz;
    int n;
public:

    ABB();
    void insertar (int nuevoElemento);
    Nodo *buscar(int elementoABuscar);
    void eliminar (int elementoAEliminar);
    void imprimir();
    bool esABB();
    bool esAVL();
    void leerArbol();
    ~ABB();

protected:
    void reemplazar(Nodo *A,Nodo *B);
    void eliminarSubarbol (Nodo *raizSubarbol);
    Nodo *buscarHueco(Nodo *raizSubarbol, int elementoAInsertar);
    Nodo *buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar);
    Nodo *buscarMaximo (Nodo *raizSubarbol);
    Nodo *buscarMinimo (Nodo *raizSubarbol);
    void eliminarNodo (Nodo *nodoParaEliminar);
    int alturaNodo(Nodo *raizSubarbol);
    void imprimirRecorrido(Nodo *raizSubarbol);
    bool esSubABB(Nodo *raizSubarbol);
    bool esSubAVL(Nodo *raizSubarbol);
    Nodo * leerSubarbol(Nodo *padre);
};

