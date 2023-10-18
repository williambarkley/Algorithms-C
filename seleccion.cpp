#include<iostream>
using namespace std;

void ordenarSeleccion(int x[],int len)
{
    int min1 = 0;
    int aux = 0;
    
  for(int i=0;i<len;i++)
    {
      min1 = i;
      for(int j = i+1;j<len;j++)
      {
          
          
          
          if (x[j]< x[min1])
          {
              min1 = j;
          }

      }

      if (x[min1] < x[i])
      {
          aux = x[i];
          x[i] = x[min1];
          x[min1] = aux;
      }
 
      
      
      


      


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
 ordenarSeleccion(x,n);
}

