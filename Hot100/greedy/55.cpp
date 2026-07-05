// 维护一个当前能到达的最大右边界right
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    vector<int> a;
    int x;

    while (cin >> x)
        a.push_back(x);

    int right = 0;
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        if (i <= right && i + a[i] > right)
            right = i + a[i];
    }
    if (right >= n - 1)
        cout << "true";
    else
        cout << "false";
}