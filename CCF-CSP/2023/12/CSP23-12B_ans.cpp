// 2023-12-B 因子化简
//? 试除法分解质因数
#include <iostream>

using namespace std;

typedef long long ll; // 题目中 n 最大到 10^10，需要 64 位整数

int main()
{
    int q; // 查询个数
    cin >> q;

    while (q--)
    { // 对每个查询进行处理
        ll n, k;
        cin >> n >> k;

        ll temp = n; // 临时变量，用于逐步分解质因数
        ll ans = 1;  // 最终简化后的值，初始为 1

        // 试除法分解质因数，i 从 2 开始
        // 只需要试到 i * i <= temp 即可，因为如果 temp 有大于 sqrt(temp) 的质因子，
        // 最多只会有一个，会在循环结束后处理
        for (ll i = 2; i * i <= temp; i++)
        {
            if (temp % i == 0)
            {                // 找到一个质因子 i
                int cnt = 0; // 统计指数
                // 不断用 i 去除 temp，直到不能整除，同时记录指数
                while (temp % i == 0)
                {
                    temp /= i;
                    cnt++;
                }

                // 如果该质因子的指数 >= k，说明它“重要”，需要保留
                if (cnt >= k)
                {
                    // 将 i^cnt 乘回到 ans 中
                    for (int j = 0; j < cnt; j++)
                    {
                        ans *= i;
                    }
                }
                // 如果 cnt < k，则不乘入 ans，相当于从原数中丢弃了这个因子
            }
        }

        // 循环结束后，temp 如果不为 1，则它是一个大于 sqrt(原 n) 的质因子
        // 由于它只可能以一次幂的形式存在（指数为 1）
        // 所以只需要判断 1 >= k 是否成立，即 k 是否为 1
        if (temp > 1 && 1 >= k)
        {                // 等价于 k == 1 时保留该因子
            ans *= temp; // 将这个最后的质因子乘入结果
        }
        // 如果 k > 1，则这个指数为 1 的质因子被认为不重要，会直接丢弃（ans 保持不变）

        cout << ans << endl; // 输出本次查询的简化结果
    }

    return 0;
}