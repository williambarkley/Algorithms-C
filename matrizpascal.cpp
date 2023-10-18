#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#include <iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;
int calcularpascal(int n, int r)
{

	int matriz[11][11];

	matriz[0][0] = 1;
	matriz[1][0] = 1;
	matriz[1][1] = 1;

	for (int i = 2; i < 11; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				matriz[i][j] = 1;
				
			}
			else if (j == i)
			{
				matriz[i][j] = 1;
				
			}
			else
			{
				matriz[i][j] = matriz[i - 1][j] + matriz[i - 1][j - 1];
			}
		}
	}
	int mat = matriz[n][r];
	cout << mat;
}

int main()
	{

	int n;
	int r;
	cin >> n >> r;
	while (n >= 0 && r >= 0)
	{
		assertdomjudge(n >= r);
		calcularpascal(n,r);
		cout << endl;
		cin >> n >> r;
	}

	}

