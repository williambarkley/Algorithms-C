#include<iostream>
using namespace std;

void movimiento(char** matriz, int i, int j, bool *exito)
{
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};
    int u = 0;
    int v = 0;



    if (*exito != true)
    {
        if((0 <= i) && (i < 10) && (0 <= j) && (j < 10))
        {
            if (matriz[i][j] == '.')
            {
                matriz[i][j] = 'X';
                for (int k = 0; k < 4; k++)
                {
                    u = i + x[k];
                    v = j + y[k];
                    movimiento(matriz, u, v, exito);
                }
                if (!*exito)
                {
                    matriz[i][j] = '.';
                }
            }
            else if (matriz[i][j] == 'T')
            {
                *exito = true;

                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        cout << matriz[i][j];
                    }
                    cout << endl;
                }
                cout << "ENCONTRADO " << i <<" " << j;
                return;
            }
        }
    }
}
int main()
{
    char** matriz;
    bool exito = false;
    matriz = new char* [10];
    char c;
    for (int i = 0; i < 10; i++)
    {
        matriz[i] = new char[10];
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> c;
            matriz[i][j] = c;
        }
    }
    movimiento(matriz, 0, 0, &exito);
    if (!exito)
    {
        cout << "INALCANZABLE" << endl;
    }
}