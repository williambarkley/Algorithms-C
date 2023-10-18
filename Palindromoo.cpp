#include<iostream>
using namespace std;

int palindromo(int x, int y, string a)
{
    while (x < (a.length() / 2))
    {
        if (a[x] == a[y - 1])
        {
            return palindromo(x + 1, y - 1, a);
        }
        else
            cout << 0;
        return 0;
    }

    cout << 1;
    return 1;
}

int main()
{
    string a;
    cin >> a;
    int y = a.length();
    int x = 0;
    palindromo(x, y, a);
}