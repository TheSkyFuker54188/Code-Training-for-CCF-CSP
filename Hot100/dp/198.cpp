/*
【ai选不选】
ai不选：f(i) = f(i - 1) 从前i−1个元素中选出最优解
ai选  ：f(i) = f(i - 2) + ai
f(i) = max(f(i - 1), f(i - 2) + ai)
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    a.push_back(0);
    int x;
    while (cin >> x)
    {
        a.push_back(x);
    }
    int n = a.size() - 1;

    int d2 = 0;
    int d1 = 0;

    for (int i = 1; i <= n; i++)
    {
        int dn = max(d1, d2 + a[i]);
        d2 = d1;
        d1 = dn;
    }
    cout << d1;
}