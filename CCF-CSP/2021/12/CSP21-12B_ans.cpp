// 2021-12-B 序列查询新解
//? 阶梯函数，只在某些临界点发生变化
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100005;
int A[MAXN];

int main()
{
    int n, N;
    cin >> n >> N;
    int r = N / (n + 1);

    A[0] = 0;
    A[n + 1] = N; // 在末尾加一个哨兵，方便处理最后一段
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    long long ans = 0;

    // i: 当前 f 值的索引
    // pos: 当前扫描到的 x 位置
    int pos = 0;
    for (int i = 0; i <= n; i++) //* 外层循环遍历 f 的每一段
    {
        int f_val = i;
        // 当前 f 值覆盖的 x 范围是 [pos, A[i+1]) 也就是[A[i], A[i+1])
        while (pos < A[i + 1]) //* 我们在这个范围内，根据 g 的变化继续分段
        {
            int g_val = pos / r;

            // 下一个跳变点的位置，也就是会引起 g 变化的位置
            //* 就是下一个 r 的倍数，即 (g_val + 1) * r
            int next_pos = min(A[i + 1], (g_val + 1) * r);//! 同时注意：不能超出 f 的区间边界 A[i+1]. 所以取两者的最小值

            // 在 [pos, next_pos) 内 f 和 g 都不变
            long long len = next_pos - pos;
            ans += len * abs(f_val - g_val);

            //* 移动 pos 到下一段的开始
            pos = next_pos;
        }
    }

    cout << ans << endl;
    return 0;
}