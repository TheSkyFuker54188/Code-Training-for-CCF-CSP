// 2022-6-A 归一化处理
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double a[n];
    double d;

    double avg = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        avg += a[i];
    }
    avg = avg / n;
    for (int i = 0; i < n; i++)
    {
        d += pow(a[i] - avg, 2);
    }
    d = d / n;
    for (int i = 0; i < n; i++)
    {
        double f = (a[i] - avg) / sqrt(d);
        cout << f << endl;
    }
}