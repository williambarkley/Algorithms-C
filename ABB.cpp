#include "ABB.h"


ABB::ABB()
{
	this->n=0;
	this->raiz=NULL;
}

ABB::~ABB()
{
	eliminarSubarbol(raiz);
}

void ABB::eliminarSubarbol(Nodo *raizSubarbol)
{
	delete raizSubarbol;
}

void ABB::insertar(int nuevoElemento)
{
	if(this->n==0)
    {
        raiz = new Nodo(nuevoElemento);
    }
	else
    {
		buscarHueco(raiz,nuevoElemento);
	}
	this->n++;
}

Nodo *ABB::buscarHueco(Nodo *raizSubarbol,int elementoAInsertar){

    Nodo *nodo=new Nodo(elementoAInsertar);
	if(raizSubarbol->numero>elementoAInsertar)
    {
        if(raizSubarbol->hijoIzquierdo==NULL)
        {
            nodo->hijoDerecho=NULL;
            nodo->hijoIzquierdo=NULL;
            nodo->padre=raizSubarbol;
            raizSubarbol->hijoIzquierdo=nodo;

            return raizSubarbol->hijoIzquierdo;
        }
        else
        {
            buscarHueco(raizSubarbol->hijoIzquierdo,elementoAInsertar);
        }

	}
    else
    {
        if(raizSubarbol->hijoDerecho==NULL)
        {
            nodo->hijoDerecho=NULL;
            nodo->hijoIzquierdo=NULL;
            nodo->padre=raizSubarbol;
            raizSubarbol->hijoDerecho=nodo;

            return raizSubarbol->hijoDerecho;
        }
        else
        {
            buscarHueco(raizSubarbol->hijoDerecho,elementoAInsertar);
        }
	}
	
}

Nodo *ABB::buscar(int elementoABuscar)
{
		return buscarRecursivo(raiz,elementoABuscar);
}

Nodo *ABB::buscarRecursivo(Nodo *raizSubarbol,int elementoABuscar)
{
	if(raizSubarbol==NULL)
    {
        return NULL;
    }
	else if(raizSubarbol->numero==elementoABuscar)
    {
        return raizSubarbol;
    }
	else if(elementoABuscar<raizSubarbol->numero)
    {
        return buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
    }
	else
    {
        return buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
    }
}

void ABB::eliminar(int elementoAEliminar)
{
	eliminarNodo(buscar(elementoAEliminar));
}

void ABB::eliminarNodo(Nodo *nodoParaEliminar)
{
	if(nodoParaEliminar->hijoIzquierdo!=NULL && nodoParaEliminar->hijoDerecho!=NULL)
    {
		
		int altIzq=alturaNodo(nodoParaEliminar->hijoIzquierdo);
		int altDrc=alturaNodo(nodoParaEliminar->hijoDerecho);

		if(altDrc<=altIzq)
        {
			Nodo *auxMax=buscarMaximo(nodoParaEliminar->hijoIzquierdo);
			nodoParaEliminar->numero=auxMax->numero; 
			eliminarNodo(auxMax);
		}
		else
        {
			Nodo *auxMin=buscarMinimo(nodoParaEliminar->hijoDerecho);
			nodoParaEliminar->numero=auxMin->numero; 
			eliminarNodo(auxMin);

		}
	}
    else if(nodoParaEliminar->hijoIzquierdo==NULL && nodoParaEliminar->hijoDerecho!=NULL)
    {
		
		Nodo *aux=buscarMinimo(nodoParaEliminar->hijoDerecho);
		reemplazar(nodoParaEliminar,aux);

	}
    else if(nodoParaEliminar->hijoDerecho==NULL && nodoParaEliminar->hijoIzquierdo!=NULL)
    {
		
		Nodo *aux=buscarMaximo(nodoParaEliminar->hijoIzquierdo);
		reemplazar(nodoParaEliminar,aux);

	}
    else
    {
		
		reemplazar(nodoParaEliminar,NULL);
	}
}

	
void ABB::reemplazar(Nodo *A,Nodo *B)
{
	if(A->padre==NULL)
    {
		if(A->hijoIzquierdo!=NULL)
        {
			Nodo *auxMax=buscarMaximo(A->hijoIzquierdo);
            A->numero=auxMax->numero;
			eliminarNodo(auxMax);
		}
		else if(A->hijoDerecho!=NULL)
        {
			Nodo *auxMin=buscarMinimo(A->hijoDerecho);
            A->numero=auxMin->numero;
			
			eliminarNodo(auxMin);
		}else{
			raiz=NULL;
		}
	}
	else if(A->padre!=NULL)
    {
		if(A->padre->hijoIzquierdo!=NULL)
        {
			if(A->numero==A->padre->hijoIzquierdo->numero)
            {
                A->padre->hijoIzquierdo=B;
			}
		}
		if(A->padre->hijoDerecho!=NULL)
        {
			if(A->numero==A->padre->hijoDerecho->numero)
            {
                A->padre->hijoDerecho=B;
			}
		}
		if(B!=NULL)
            B->padre=A->padre;
	}
	this->n--;
}
		
	


Nodo *ABB::buscarMaximo(Nodo *raizSubarbol)
{
	if(raizSubarbol->hijoDerecho!=NULL)
    {
      buscarMaximo(raizSubarbol->hijoDerecho);
    }
	else
		return (raizSubarbol);
}
		
Nodo *ABB::buscarMinimo(Nodo *raizSubarbol){
	
	if(raizSubarbol->hijoIzquierdo!=NULL){
       buscarMinimo(raizSubarbol->hijoIzquierdo);
    }
	else
		 return (raizSubarbol);
		
		
}


int ABB::alturaNodo(Nodo *raizSubarbol){
	
	
	int AltIzq=0;
	int AltDer=0;

    if(raizSubarbol==NULL)
        return -1;
	
    else{
		
        AltIzq = alturaNodo(raizSubarbol->hijoIzquierdo);
        AltDer = alturaNodo(raizSubarbol->hijoDerecho);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
	
}




bool ABB::esAVL(){
	
	if(raiz==NULL)
		return true;
	else if(esABB())
		return esSubAVL(raiz);
	
	else
		return false;
	
	
}

bool ABB::esSubAVL(Nodo *raizSubarbol){
	
		

        if(raizSubarbol == NULL)
                return 1;
			
        int left_height = alturaNodo(raizSubarbol->hijoIzquierdo);
        int right_height = alturaNodo(raizSubarbol->hijoDerecho);
  
        if( abs(left_height - right_height) <=1 &&  esSubAVL(raizSubarbol->hijoIzquierdo) && esSubAVL(raizSubarbol->hijoDerecho) )
                return 1;
        return 0;

	
}


bool ABB::esABB(){
	
	if(raiz==NULL)
		return true;
	else
		return esSubABB(raiz);
	
	
}









bool ABB::esSubABB(Nodo *raizSubarbol){


	if(raizSubarbol->hijoIzquierdo != NULL)
		if(buscarMaximo(raizSubarbol->hijoIzquierdo)->numero > raizSubarbol->numero)		
			return false;
		
		
    if(raizSubarbol->hijoDerecho != NULL)
		if(buscarMinimo(raizSubarbol->hijoDerecho)->numero < raizSubarbol->numero)	
			return false;
	
	
	//SI SON EL ULTIMO NODO ES VERDAD QUE ES UN ABB
	if(raizSubarbol->hijoIzquierdo == NULL)
		return true;

	if(raizSubarbol->hijoDerecho == NULL)
		return true;
		
	//Comprobmaos la siguiente subraiz
	if(!esSubABB(raizSubarbol->hijoIzquierdo) || !esSubABB(raizSubarbol->hijoDerecho))
		return false;


    return true;
	
	
}








void ABB::imprimir()
{
  if(raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
      imprimirRecorrido(raiz);    
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
  cout<<raizSubarbol->numero<<endl;
  if(raizSubarbol->hijoIzquierdo!=NULL)
    {
      cout<<"I";
      imprimirRecorrido(raizSubarbol->hijoIzquierdo);
      cout<<endl;
    }
  if(raizSubarbol->hijoDerecho!=NULL)
    {
      cout<<"D";
      imprimirRecorrido(raizSubarbol->hijoDerecho);
      cout<<endl;
    }
}



void ABB::leerArbol()
{
  raiz=leerSubarbol(NULL);
}



Nodo *ABB::leerSubarbol(Nodo *padre){
  int numero;
  cin>>numero;
  if(numero>=0)
    {
      Nodo *arbol=new Nodo;
      arbol->numero=numero;
      arbol->hijoIzquierdo=leerSubarbol(arbol);
      arbol->hijoDerecho=leerSubarbol(arbol);
      arbol->padre=padre;
      return arbol;
    }
  else
    {
      return NULL;
    }
}

