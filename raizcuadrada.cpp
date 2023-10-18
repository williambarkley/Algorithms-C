#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#include<iostream>
using namespace std;

float raizcuadrada(float a, float n, float r, float c)
{

	float res = ((a + c) / 2);

	if ((n - (res * res)) > r)
	{
		cout << res << " ";
		cout << endl;
		return raizcuadrada(res, n, r, c);
	}
	else if (((res * res) - n) > r)
	{
		cout << res << " ";
		cout << endl;
		return raizcuadrada(a, n, r, res);

	}
	else
	{
		cout << res << " ";
		cout << endl;
		return res;
	}

}

int main()
{
	float n;
	float r;
	float a = 0;
	cin >> n;
	cin >> r;
	float c = n;
	assertdomjudge((n > 0)&&(r > 0));
	raizcuadrada(a, n, r, c);

}