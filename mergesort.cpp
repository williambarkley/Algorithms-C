#include<iostream>
using namespace std;

void  combinar (int a[ ] , int len_a , int b[ ] , int len_b , int c[ ])
{
    int aI = 0;
    int aD = 0;

    while (aI + aD < len_a + len_b)
    {
        if (aI == len_a)
        {
            c[aI + aD] = b[aD];
            aD++;
        }

        else if (aD == len_b)
        {
            c[aI + aD] = a[aI];
            aI++;
        }

        else if (a[aI] == b[aD])
        {
            c[aI + aD] = a[aI];
            aI++;

            c[aI + aD] = b[aD];
            aD++;
        }
        else if (a[aI] < b[aD])
        {
            c[aI + aD] = a[aI];
            aI++;
        }

        else if (a[aI] > b[aD])
        {
            c[aI + aD] = b[aD];
            aD++;
        }
    }
}


void ordenarMergeSort (int x[], int len)
{
  int temp[len];
  if (len<=1)
    return;
  else
    {
      int L = len / 2;
      ordenarMergeSort(&x[0], len/2);
      ordenarMergeSort(&x[L],(len - L));

      combinar(&x[0], L, &x[L], len - L, temp);

      for (int i; i < len; i++)
      {
          x[i] = temp[i];
      }
   
      for (int k = 0; k < len; k++)
	{
	  x[k] = temp[k];
	  cout<<x[k]<<" ";
	}
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
 ordenarMergeSort(x,n);
}

