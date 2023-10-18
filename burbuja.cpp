#include<iostream>
using namespace std;

void ordenarBurbuja(int x[],int len)
{
    int y = 0;
  for(int i=1;i<len;i++)
    {
      for (int j = 0; j < len-1; j++)
      {
          if (x[j+1] < x[j])
          {
              y = x[j];
              x[j] = x[j+1];
              x[j+1] = y;

          }
          
      }
      len - i;
      
      /*Añadir código de ordenación usando algoritmo de burbuja*/
      

      /*No tener en cuenta el siguiente bucle de impresion  para el calculo de la complejidad*/
      for(int k=0;k<len;k++)
	cout<<x[k]<<" ";
      cout<<endl;
    }  
}


int main()
{
 int n;
 cin>>n;
 int *x=new int[n];
 
 for(int i=0;i<n;i++)
   cin>>x[i];
 ordenarBurbuja(x,n);
}
