// 2024-12-B 梦境巡查
//? 前缀和
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    // a[i]：从 i 到 i+1 消耗的能量 (i=0..n)
    vector<int> a(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }

    // b[i]：到达 i 后获得的补给 (i=1..n)，b[0] 恒为 0
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
    }

    // 计算 S[k] = sum_{i=0..k} a_i - sum_{i=1..k} b_i
    vector<int> S(n + 1);
    long long sumA = 0, sumB = 0; // 使用 long long 避免累加时溢出
    for (int i = 0; i <= n; ++i)
    {
        sumA += a[i];
        if (i >= 1)
            sumB += b[i];
        S[i] = (int)(sumA - sumB); // 题目保证差值在 int 范围内
    }
    //? pre_max[j] —— 前半段（没受影响）最大值 ( 0 ~ j-1 )
    //? suf_max[j] —— 后半段（会受影响）最大值 ( j ~ n )

    // pre_max[j] = max(S[0], S[1], ..., S[j-1])
    // 令 pre_max[1] = S[0]，方便边界处理
    vector<int> pre_max(n + 2);
    pre_max[1] = S[0];
    for (int j = 2; j <= n; ++j)
    { //? 从前往后递推
        pre_max[j] = max(pre_max[j - 1], S[j - 1]);
    }

    // suf_max[j] = max(S[j], S[j+1], ..., S[n])
    vector<int> suf_max(n + 2);
    suf_max[n] = S[n];
    for (int j = n - 1; j >= 1; --j)
    { //? 从后往前递推
        suf_max[j] = max(suf_max[j + 1], S[j]);
    }

    // 对每个意外位置 j 计算答案并输出
    for (int j = 1; j <= n; ++j)
    {
        int ans = max(pre_max[j], suf_max[j] + b[j]);
        // 输出，最后一个数字后换行，其余后加空格
        printf("%d%c", ans, j == n ? '\n' : ' ');
    }
    return 0;
}