/*
使用两个堆，
大根堆维护左半边的元素（也就是小于中位数的那些数），
小根堆维护右半边的元素（也就是大于等于中位数的那些数）

查询的时候，如果两个堆的大小相等，此时数组长度为偶数，
则取两者的堆顶的平均值，否则取大小更大的那个堆的堆顶即可
*/

#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int q;
    cin >> q; // 操作次数

    priority_queue<int> left;                             // 大根堆，存较小的一半
    priority_queue<int, vector<int>, greater<int>> right; // 小根堆，存较大的一半

    string op;
    while (q--)
    {
        cin >> op;
        if (op == "add")
        {
            int num;
            cin >> num;

            // 插入到正确的堆
            if (!right.empty() && num >= right.top())
            {
                right.push(num);
            }
            else
            {
                left.push(num);
            }

            // 平衡两个堆，使它们的大小差不超过 1
            if (left.size() > right.size() + 1)
            {
                right.push(left.top());
                left.pop();
            }
            if (right.size() > left.size() + 1)
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if (op == "median")
        {
            double ans;
            if (left.size() > right.size())
            {
                ans = left.top(); // 奇数个，左边多一个
            }
            else if (right.size() > left.size())
            {
                ans = right.top(); // 奇数个，右边多一个
            }
            else
            {
                ans = (left.top() + right.top()) / 2.0; // 偶数个，取平均
            }
            printf("%.1f\n", ans); // 保留一位小数
        }
    }

    return 0;
}