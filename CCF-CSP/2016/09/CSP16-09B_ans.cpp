// 2016年09月 第B题
// 算法 + 数据结构）

#include <iostream>

using namespace std;

int used[20]; // 记录每一排已经卖出的座位数（初始化为 0）
int n, p;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> p;
        bool allocated = false;

        // 尝试分配在同一排
        for (int i = 0; i < 20; i++)
        {
            if (5 - used[i] >= p)
            {
                for (int j = 0; j < p; j++)
                {
                    cout << i * 5 + used[i] + 1 << " ";
                    used[i]++;
                }
                cout << endl;
                allocated = true;
                break;
            }
        }

        // 如果不能分配在同一排，那就见缝插针
        if (!allocated)
        {
            for (int i = 0; i < 20 && p > 0; i++)
            {
                while (used[i] < 5 && p > 0)
                {
                    cout << i * 5 + used[i] + 1 << " ";
                    used[i]++;
                    p--;
                }
            }
            cout << endl;
        }
    }
    return 0;
}