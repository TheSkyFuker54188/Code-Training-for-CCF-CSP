#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int d2 = 1;
    int d1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int dn = d1 + d2;
        d2 = d1;
        d1 = dn;
    }

    cout << d1;
}