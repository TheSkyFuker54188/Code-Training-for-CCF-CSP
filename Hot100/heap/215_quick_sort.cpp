#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 快速选择算法，在nums中寻找第k大的元素
int quickSelect(vector<int> &nums, int k)
{
    // 随机选择一个基准元素
    int pivot = nums[rand() % nums.size()];
    vector<int> big, equal, small;
    // 将元素划分到三个数组中
    for (int num : nums)
    {
        if (num > pivot)
            big.push_back(num);
        else if (num < pivot)
            small.push_back(num);
        else
            equal.push_back(num);
    }
    // 第k大元素在大于pivot的big数组中
    if (k <= big.size())
        return quickSelect(big, k);
    // 第k大元素在小于pivot的small数组中
    if (nums.size() - small.size() < k)
        return quickSelect(small, k - nums.size() + small.size());
    // 第k大元素就是pivot
    return pivot;
}

// 对外接口：寻找第k大元素
int findKthLargest(vector<int> &nums, int k)
{
    return quickSelect(nums, k);
}

int main()
{
    // 设置随机种子，保证每次运行划分随机
    srand(static_cast<unsigned>(time(nullptr)));

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    cout << findKthLargest(nums, k) << endl;
    return 0;
}