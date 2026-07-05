/* 将后面的「大数」与前面的「小数」交换
增加的幅度尽可能的小：
尽可能靠右的低位 进行交换，需要 从后向前 查找；
尽可能小的「大数」 与前面的「小数」交换；
换到前面后，需要将「大数」后面的所有数 重置为升序 */

/* 从后向前 查找第一个 相邻升序 的元素对 (i,j) : A[i] < A[j]（[j,end) 必然是降序）
    在 [j,end) 从后向前 查找第一个满足 A[i] < A[k] 的 k
    A[i]、A[k] 分别就是上文所说的「小数」、「大数」
    swap(A[i],A[k])
[j,end) 必然是降序，逆置 [j,end)，使其升序
? 升序会让增加幅度尽可能小
    如果在步骤 1 找不到符合的相邻元素对，说明当前 [begin,end) 为一个降序顺序，则直接跳到步骤 4 */
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
    // 试图找到第一个可以被替换的低位
    // 找到一个打破降序的位置 i
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    }

    if (i >= 0)
    { // 2. 在 [i+1, n) 中从后向前找第一个大于 nums[i] 的数
        int j = n - 1;
        while (j >= i + 1 && nums[j] <= nums[i])
        {
            j--;
        }
        // 3. 交换
        swap(nums[i], nums[j]);
    }

    // 4. 反转 [i+1, n) 区间
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
