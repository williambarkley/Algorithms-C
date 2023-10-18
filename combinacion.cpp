#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#include<iostream>
using namespace std;

int factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return factorial(n - 1) * n;
}

int combinacion(int n, int r)
{
	int res = 0;
	res = factorial(n) / (factorial(r) * factorial(n - r));
	cout << res;
	return res;

}

int main()
{
	int n;
	int r;
	cin >> n >> r;

	while (n >= 0 && r >= 0)
	{
		assertdomjudge(n >= r);
		combinacion(n, r);
		cout << endl;
		cin >> n >> r;
	}

	return 0;


}