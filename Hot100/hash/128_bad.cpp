#include <iostream>
#include <unordered_map>
//! 基于排序的解法都超时了 排序至少   O（nlogn）
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    unordered_map<int, int> m;
    //            num, length
    int max_num = 0;
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        if (tem > max_num)
            max_num = tem;
        m[tem] = 1;
    }
    int max = 1;
    for (auto &item : m)
    {
        int i = item.first;
        if (m[i - 1])
        {
            m[i] = m[i - 1] + 1;
            if (m[i] > max)
                max = m[i];
        }
    }
    cout << max;
}