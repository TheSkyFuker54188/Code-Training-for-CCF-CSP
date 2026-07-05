//? 小根堆
// priority_queue 中作为第三个模板参数，将默认的
// 大根堆比较规则改为“大于”greater<int>，从而构建小根堆
#include <iostream>
#include <vector>
#include <queue>
#include <functional> //std::greater<T>
// 用大根堆排序，然后连续取堆顶的k个元素，最后一个取出来的就是答案但是堆排序的复杂度是O(nlogn)的
// 用小根堆比大根堆快，根本原因在于 堆的大小不同，导致每次操作的代价从 O(log n) 降到了 O(log k)
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    // 构建一个大小为 k 的小根堆（优先队列）
    priority_queue<int, vector<int>, greater<int>> heap;
    // 第一个参数：堆中存储的元素的类型
    // 第二个参数：底层容器
    // 第三个参数：比较器

    // 遍历数组中的每个元素
    for (int num : nums)
    {
        heap.push(num); // 将当前元素加入堆中
        if (heap.size() > k)
        {               // 如果堆的大小超过 k
            heap.pop(); // 弹出堆顶最小的元素，保持堆大小为 k
        }
        // 每次淘汰的都是当前堆里最小的那一个，因此剩下的一定是相对较大的数
        // 遍历全部结束后，堆里剩下的就是全数组最大的 k 个数
    }

    // 堆中始终保存着当前最大的 k 个元素，堆顶即为第 k 大的元素
    return heap.top();
}

int main()
{
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