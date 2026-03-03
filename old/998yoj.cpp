#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> num_map; // 哈希表存储数组元素及其下标

    for (int i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i]; // 计算当前元素的补数

        // 如果补数在哈希表中，则找到了两个数
        if (num_map.find(complement) != num_map.end())
        {
            // 返回两个数的索引，按升序排列
            return {min(i, num_map[complement]), max(i, num_map[complement])};
        }

        // 将当前元素存入哈希表
        num_map[nums[i]] = i;
    }

    // 如果找不到解，返回 -1
    return {-1};
}

int main()
{
    int n, target;

    // 输入数组长度和目标值
    cin >> n >> target;
    vector<int> nums(n);

    // 输入数组元素
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    // 调用函数获取结果
    vector<int> result = twoSum(nums, target);

    // 输出结果
    if (result.size() == 1 && result[0] == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result[0] << " " << result[1] << endl;
    }

    return 0;
}
