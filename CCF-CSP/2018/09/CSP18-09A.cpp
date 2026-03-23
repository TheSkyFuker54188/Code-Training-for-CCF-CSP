// 2018-09-A 卖菜
#include <iostream>

using namespace std;

const int MAX = 1000 + 1;
int n;
int a[MAX];
int b[MAX];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    b[1] = (a[1] + a[2]) / 2;
    b[n] = (a[n - 1] + a[n]) / 2;

    for (int i = 2; i <= n - 1; i++)
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;

    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";

    return 0;
}