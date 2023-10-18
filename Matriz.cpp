#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

Matriz::Matriz()
{
   n_filas = 0;
   n_columnas = 0;
   matriz = NULL; 
}

Matriz::Matriz(int n_filas,int n_columnas)
{
    this->n_filas = n_filas;
    this->n_columnas = n_columnas;
    

    matriz = new double*[n_filas];

    for(int i = 0; i < n_filas;i++)
    {
        matriz[i] = new double[n_columnas];
    }
    
}

Matriz::Matriz(const Matriz &matriz)
{
  this->n_filas = matriz.n_filas;
  this->n_columnas = matriz.n_columnas;
  

  this->matriz = new double*[n_filas];

  for (int i=0; i<n_filas; i++)
  {
    this->matriz[i] = new double[n_columnas];
    for(int j=0; j < n_columnas; j++)
    {
      this->matriz[i][j]=matriz.matriz[i][j];
    }
  }
}

Matriz::~Matriz()
{
    for(int i = 0;i < n_filas;i++)
    {
        delete[]matriz[i];
    }
    delete[]matriz;
}


//Asignacion de matrices

Matriz& Matriz::operator= (const Matriz &m)
{
  if(matriz!=NULL)
    {
      for (int i = 0; i < n_filas; i++)
	delete[] matriz[i];
      
      delete[] matriz;
      matriz=NULL;
    }

  this->n_filas=m.n_filas;
  this->n_columnas=m.n_columnas;
  this->matriz=NULL;
  if(n_filas>0 && n_columnas>0)
    {
      matriz= new double *[n_filas];
  
      for (int i = 0; i < n_filas; i++)
	{
	  matriz[i] = new double[n_columnas];  
	  for(int j=0; j <n_columnas; j++)
	    matriz[i][j]=m.matriz[i][j];
	}
    }
  
    return(*this); 
}

Matriz Matriz::operator+ (const Matriz &m)
{
    assertdomjudge(n_filas == m.n_filas && n_columnas == m.n_columnas);
    Matriz m1(m.n_filas,m.n_columnas);
    for(int i = 0;i < m.n_filas;i++)
    {
        for(int j = 0;j < m.n_columnas;j++)
        {
            m1.matriz[i][j] = matriz[i][j] + m.matriz[i][j];
        }

    }
    return m1;


}

Matriz Matriz::operator- (const Matriz &m)
{
    assertdomjudge(n_filas == m.n_filas && n_columnas == m.n_columnas);
    Matriz m1(m.n_filas,m.n_columnas);
    for(int i = 0;i < m.n_filas;i++)
    {
        for(int j = 0;j < m.n_columnas;j++)
        {
            m1.matriz[i][j] = matriz[i][j] - m.matriz[i][j];
        }

    }
    return m1;

}
Matriz Matriz::operator* (const double escalar)
{
    Matriz m1(n_filas,n_columnas);
    for(int i = 0;i < n_filas;i++)
    {
        for(int j = 0;j < n_columnas;j++)
        {
            m1.matriz[i][j] = matriz[i][j] * escalar;
        }

    }
    return m1;

}

Matriz Matriz::operator* (const Matriz& m)
{
    assertdomjudge(n_filas == m.n_filas && n_columnas == m.n_columnas);
    Matriz m1(n_filas, m.n_columnas);
    for (int i = 0; i < n_filas; i++)
    {

        for (int j = 0; j < m.n_columnas; j++)
        {
            
            for (int z = 0; z < this->n_columnas; z++)
            {
                m1.matriz[i][j] += matriz[i][z] * m.matriz[z][j];
            }
        }

    }
    return m1;
}
bool Matriz::esSimetrica() 
{

    if (n_filas != n_columnas)
        return false;

    for (int i = 0; i < n_filas; i++)
        for (int j = i; j < n_columnas; j++)
            if (matriz[i][j] != matriz[j][i])
                return false;

    return true;
}

double Matriz::obtenerMaximo()
{
    double MX = 0;
    Matriz m1(n_filas, n_columnas);
    for (int i = 0; i < n_filas; i++)
    {

        for (int j = 0; j < n_columnas; j++)
        {

            if (matriz[i][j] > MX)
                MX = matriz[i][j];
        }

    }
    return MX;
}

double Matriz::obtenerMinimo()
{
    double MN = matriz[0][0];
    Matriz m1(n_filas, n_columnas);

    for (int i = 0; i < n_filas; i++)
    {

        for (int j = 0; j < n_columnas; j++)
        {

            if (matriz[i][j] < MN)
                MN = matriz[i][j];
        }

    }
    return MN;
}

Matriz Matriz::calcularTraspuesta()
{
    Matriz m1(n_columnas, n_filas);

    for (int i = 0; i < n_filas; i++)
        for (int j = i; j < n_columnas; j++)
            m1.matriz[i][j] = matriz[j][i];

    return m1;
                
}







// Leer matriz
void Matriz::rellenarManual()
{
  double elemento;
  for (int i = 0; i < n_filas; i++)
    {
      cout << "Fila " << i << endl;
      for (int j = 0; j < n_columnas; j++)
	{
	  cout << "Elemento " << j  << endl;
	  cin >> elemento;
	  matriz[i][j] = elemento;
        }
      cout << endl;
    }
  
}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
  srand(seed);
  for (int i = 0; i < n_filas; i++)
    for (int j = 0; j < n_columnas; j++)
      matriz[i][j]=rand();
  
}



// Imprimir Matriz
void Matriz::mostrarMatriz()
{
  for (int i = 0; i < n_filas; i++)
      {
	for (int j = 0; j < n_columnas; j++)
	  cout << matriz[i][j] << " ";       
        cout << endl;
    }
}

