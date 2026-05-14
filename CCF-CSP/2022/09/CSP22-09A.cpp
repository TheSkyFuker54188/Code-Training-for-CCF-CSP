// 2022-9-A 如此编码
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    int b[n + 1];
    int c[n + 1];

    c[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        c[i]=1;
        b[i] = 0;
        cin >> a[i];
        //cout << a[i];
        int j = i;
        while (j > 0)
        {
            c[i] *= a[j];
            j--;
        }
    }

    int las = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = m % c[i];
        b[i] = (tmp - las) / c[i - 1];
        las = tmp;
    }
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
}