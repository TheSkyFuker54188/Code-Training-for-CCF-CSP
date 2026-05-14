// 2022-12-A 现值计算
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    double I;
    //freopen("in.txt", "r", stdin);
    cin >> n >> I;

    double c[n + 1];
    double p = 0;
    for (int i = 0; i <= n; i++)
    {
        cin >> c[i];
        p += c[i] * pow(1 + I, -i);
    }
    cout << p;
}