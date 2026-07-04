#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int m, n;
    cin >> m;
    vector<int> nums1(m);
    for (int i = 0; i < m; ++i)
        cin >> nums1[i];
    cin >> n;
    vector<int> nums2(n);
    for (int i = 0; i < n; ++i)
        cin >> nums2[i];

    int len = m + n;
    //! 奇数：val1 == val2
    //! 偶数：[val1 , val2]  左右中位数
    int k1 = (len + 1) / 2; // 左中位数位置（从1开始）
    int k2 = (len + 2) / 2; // 右中位数位置（奇偶统一）

    int i = 0, j = 0, count = 0;
    double val1 = 0, val2 = 0;

    while (count < k2)
    {
        int cur;

        // 情况1: nums1 和 nums2 都还有元素，比较它们当前值的大小
        if (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                cur = nums1[i];
                i++;
            }
            else
            {
                cur = nums2[j];
                j++;
            }
        }
        // 情况2: 只有 nums1 还有元素
        else if (i < m)
        {
            cur = nums1[i];
            i++;
        }
        // 情况3: 只有 nums2 还有元素（或两者都空，但 count<k2 保证不会出现）
        else
        {
            cur = nums2[j];
            j++;
        }

        count++;

        if (count == k1)
            val1 = cur;
        if (count == k2)
            val2 = cur;
    }

    double ans = (val1 + val2) / 2.0;
    cout << fixed << setprecision(5) << ans << endl;
    return 0;
}