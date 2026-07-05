// 先用哈希统计元素出现频次。然后对(频次,值)二元组用固定大小为k的小根堆维护
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, int> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        x[a[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    for (auto i : x)
    {
        int num = i.first;
        int freq = i.second;

        heap.push({freq, num});
        if (heap.size() > k)
            heap.pop();
    }

    vector<int> ans;
    while (!heap.empty())
    {
        ans.push_back(heap.top().second);
        heap.pop();
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
}