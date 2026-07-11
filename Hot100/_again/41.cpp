#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) // todo 遍历的是每个位置
    {
        while (a[i] > 0 && a[i] < n && //! 确保只处理在 [1, n] 范围内的正整数
                                       // todo 数字 x（a[i]） 应该放在索引 x-1 的位置
               a[a[i] - 1] != a[i]) // todo 如果索引 x-1 处值（ a[a[i]-1] ）不为x（a[i]），那就交换 => 摆正 x
        {
            swap(a[i], a[a[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
        {
            cout << i + 1;
            return 0;
        }
    }
}