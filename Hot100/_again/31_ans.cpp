#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    // 1. 从后向前找第一个升序对 (i, i+1)，满足 nums[i] < nums[i+1]
    int i = n - 2; // todo 【第一要求】i 尽量靠右
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    } //! 没找到则 i = -1

    if (i >= 0)
    {                  // 2. 在 [i+1, n) 中从后向前找第一个大于 nums[i] 的数
        int j = n - 1; // todo 【第二要求】j尽量小（在降序序列中从右往左找，自然满足从小到大找）
        while (j >= i + 1 && nums[j] <= nums[i])
        {
            j--;
        }
        // 3. 交换
        swap(nums[i], nums[j]);
    }

    // 4. 反转 [i+1, n) 区间
    // todo 【第三要求】翻转使后缀变最小 —— 把 i 后面的部分翻转成升序。
    reverse(nums.begin() + i + 1, nums.end());

    // 输出结果
    for (int k = 0; k < n; ++k)
    {
        if (k > 0)
            cout << " ";
        cout << nums[k];
    }
    cout << endl;

    return 0;
}
