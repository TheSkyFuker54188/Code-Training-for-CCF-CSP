// 2022-9-B 何以包邮？
// DP / 背包问题
#include <iostream>
#include <vector>
#include <numeric>
//* 问题可以转化为：在 n个物品中选择若干个，在保证总价值大于等于 x 的前提下
//* 使得总价值最小
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    if (!(cin >> n >> x))
        return 0;

    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    //* dp[j] 表示是否存在一种选书方案使得总价格正好为 j
    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    // 01背包的一维空间优化写法 //! 01背包问题 空间优化时必须倒序
    for (int i = 0; i < n; ++i)
    {
        for (int j = sum; j >= a[i]; --j)
        { //! 必须倒序 —— 前置状态必定为历史状态。如果正序就会导致 “同一本书会被重复购买多次” 的错误逻辑
            //* 对每一本书的价格 a[i] ，使用从大到小的倒序遍历更新 dp 数组
            if (dp[j - a[i]]) //* 转移方程:
            {                 //* 如果没当前物品时能凑出 j-物品[i]，
                dp[j] = true; //* 那现在就能凑出 j
            }
        }
    }

    //* 从 x 开始向后找，第一个为 true 的 j 即为大于等于 x 的最小可行总价
    for (int j = x; j <= sum; ++j)
    {
        if (dp[j])
        {
            cout << j << "\n";
            return 0;
        }
    }

    return 0;
}

/*
* // 1. 根据最大的可能总和，开一个布尔数组，初始化全为 false
vector<bool> dp(MAX_SUM + 1, false);
dp[0] = true; // 2. 什么都不选，总和为0，永远是可行的

* // 3. 外层循环：一本一本枚举所有物品
for(int i = 0; i < n; i++) {
    * // 4. 内层循环：金额从大到小倒序遍历！终点是遍历到当前物品的大小为止。
    for(int j = MAX_SUM; j >= 物品[i]; j--) {
        * // 5. 转移方程：如果没当前物品时能凑出 j-物品[i]，那现在就能凑出 j
        if(dp[j - 物品[i]]) {
            dp[j] = true;
        }
    }
}
    */