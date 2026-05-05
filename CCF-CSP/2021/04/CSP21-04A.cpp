// 2021-4-A 灰度直方图
#include <iostream>

using namespace std;

int main()
{
    int n, m, L;
    cin >> n >> m >> L;
    int l[L];
    for (int i = 0; i < L; i++)
        l[i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            l[tmp]++;
        }
    }
    cout << l[0];
    for (int i = 1; i < L; i++)
        cout << " " << l[i];
}