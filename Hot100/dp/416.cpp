//? 0-1 背包
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums;
    int x;
    while (cin >> x)
    {
        nums.push_back(x);
    }

    int total = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        total += nums[i];
    }

    // 如果总和是奇数，不能平分
    if (total % 2 != 0)
    {
        cout << "false" << endl;
        return 0;
    }

    int target = total / 2;
    // dp[j] 表示是否能凑出和为 j
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];
        for (int j = target; j >= num; --j) //!  倒着更新杜绝重复
        {
            if (dp[j - num]) // 如果之前已经能凑出和 j - num，那么现在再加上当前数字 num，就恰好能凑出 j
            {
                dp[j] = true;
            }
        }
    }
    /*     
    倒序保证：在考虑 dp[j] 时，
    所有比 j 小的状态都还没有被当前的 num 更新过，
    它们代表的是“没有当前数字”的旧状态，相当于我们只用上一次循环的结果。
    这样每个数字只会在它自己的这一轮被使用一次，
    不会在后面的大 j 中被重复使用 
    */

    // 用 if-else 输出（替代三元运算符）
    if (dp[target])
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}