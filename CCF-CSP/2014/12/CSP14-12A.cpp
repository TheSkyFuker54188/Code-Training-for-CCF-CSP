// 2014年12月 第A题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

int n;
int u[1001];

int main()
{
    int a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        u[a]++;
        cout << u[a] << " ";
    }
    return 0;
}