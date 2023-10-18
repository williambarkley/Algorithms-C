#include<iostream>
using namespace std;

int movimiento(int a, int n)
{
    int chutaperro[n];
    int aux = 0;



    for(int i = 0; i<n ;i++)
    {
        chutaperro[i] = a;
        aux += chutaperro[i];

        if (aux == n)
        {
            for (int k = 0; k <= i; k++)
            {
                printf("%d ", chutaperro[i]);
            }
            printf("\n");

            for(int i = n-1; i>=0 ;i--)
            {
                int aux2 = 0;
                chutaperro[i] = a+1;

                for(int k = 0; k<=i ;k++)
                {
                    aux2 += chutaperro[k];
                }

                if (aux2 == n)
                {
                    for (int k = 0; k <= i; k++)
                    {
                        printf("%d ", chutaperro[k]);
                    }
                    printf("\n");
                    chutaperro[i] = a;
                }
                else if(aux2 > n)
                {
                    chutaperro[i] = 0;
                }
            }
        }

    }




    if(a < n-1)
    {
        movimiento((a + 1), n);
    }


    return 0;
}



int main()
{
    int a = 0;
    int n = 0;
    int g = 0;
    cin >> n;
    movimiento(a,n);

}

