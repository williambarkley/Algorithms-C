#include<iostream>
using namespace std;

void ordenarInsercion(int x[],int len)
{
    int j=0;
    int l = 0;
  for(int i=1;i<len;i++)
    {
         
            j = i - 1;
            l = x[i];
            while (j >= 0 && x[j] > l)
            {
                x[j + 1] = x[j];
                j--;
            }
            x[j + 1] = l;

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
 ordenarInsercion(x,n);
}


