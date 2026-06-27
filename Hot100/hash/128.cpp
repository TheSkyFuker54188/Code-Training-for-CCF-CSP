#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    unordered_set<int> s(nums.begin(), nums.end());

    /* for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        s.insert(tem);
     ? 另一种插入set方式（逐值插入）
    } */

    int max_l = 1;
    for (auto &item : s)
    {
        int length = 1;
        if (s.find(item - 1) == s.end())
        {
            int cur = item;
            // int length = 1;
            while (s.find(cur + 1) != s.end())
            {
                cur++;
                length++;
            }
        }
        max_l = max(max_l, length);
    }

    cout<<max_l;
}
