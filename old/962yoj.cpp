#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;

const int MAXN = 3000000; // 提前定义最大可能的输入大小
int heights[MAXN + 5];    // 提前分配数组，避免频繁动态内存分配

int largestRectangleArea(int n)
{
    stack<int> s;
    int maxArea = 0;

    for (int i = 0; i <= n; ++i)
    {
        int h = (i == n ? 0 : heights[i]); // 在最后加一个高度为0的哨兵
        while (!s.empty() && h < heights[s.top()])
        {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    return maxArea;
}

int main()
{
    ios::sync_with_stdio(false); // 关闭C++的同步IO，提高速度
    cin.tie(nullptr);            // 解绑定 cin 和 cout

    int n;
    scanf("%d", &n); // 使用更快的输入方式
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &heights[i]); // 快速读入高度数组
    }

    printf("%d\n", largestRectangleArea(n)); // 快速输出结果
    return 0;
}
