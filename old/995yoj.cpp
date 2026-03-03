#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int currentSum = nums[0]; // 当前子数组的和
    int maxSum = nums[0];     // 全局最大和

    for (int i = 1; i < nums.size(); ++i)
    {
        // 如果当前子数组的和小于0，则重新开始一个新的子数组
        currentSum = max(nums[i], currentSum + nums[i]);
        // 更新全局最大和
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main()
{
    int n;

    // 输入数组长度
    cin >> n;
    vector<int> nums(n);

    // 输入数组元素
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    // 输出最大子数组和
    cout << maxSubArray(nums) << endl;

    return 0;
}
