#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
 private:
  double **matriz;
  
  int n_filas;
  int n_columnas;

 public:

/* inicializa valores a 0.
	   Parámetro: ninguno.
	   Retorno: ninguno.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(1)
	   Complejidad Espacial: O(1)


*/

Matriz();

/* inicializa valores filas columnas.
	   Parámetro: int n_filas,int n_columnas.
	   Retorno: ninguno.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

Matriz(int n_filas,int n_columnas);

/* reservo tamaño para copiar una matriz.
	   Parámetro: la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

Matriz(const Matriz &matriz);

/*destruye la matriz.
	   Parámetro: ninguno
	   Retorno: ninguno.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas)
	   Complejidad Espacial: O(1)


*/

~Matriz();
/*  suma dos matrices.
	    Parámetro: la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/



Matriz operator+ (const Matriz &m);

/* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
	   Parámetro: la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/


  Matriz& operator= (const Matriz &m);


/*resta dos matrices 
	    Parámetro: la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/


Matriz operator- (const Matriz &m);

/* multiplica una matriz por un escalar
	    Parámetro: escalar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

Matriz operator* (const double escalar);

/* multiplicar una matriz por otra
	  Parámetro: la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

Matriz operator* (const Matriz &m);
/* te dice si la matriz es simetrica 
	   Parámetro: Ninguno
	   Retorno: bool
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/
 bool esSimetrica();
 /* te devuelve un double con el valor maximo
	   Parámetro: Ninguno
	   Retorno: double
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

 double obtenerMaximo();
 /* te devuelve el minimo double
	   Parámetro: Ninguno
	   Retorno: double
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/
 double obtenerMinimo();
 /* devuelve la matriz transpuesta
	   Parámetro: Ninguno
	   Retorno: Matriz
	   Precondicion: 
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

 Matriz calcularTraspuesta();
 /* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/



  
  void rellenarManual();


/* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria 
	   Parámetro: semilla que se utiliza para el generador aleatorio
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void rellenarAleatorio(long seed);



/* Imprime por pantalla todos los elementos de la matriz del objeto actual  
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void mostrarMatriz();
  
};

#endif // MATRIZ_H
