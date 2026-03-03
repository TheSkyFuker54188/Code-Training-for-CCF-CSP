#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int a(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + nums[i];
    }
    deque<int> minSum;
    int minLength = n + 1;
    for (int i = 0; i <= n; i++)
    {
        while (!minSum.empty() && sum[i] - sum[minSum.front()] >= k)
        {
            minLength = min(minLength, i - minSum.front());
            minSum.pop_front();
        }
        while (!minSum.empty() && sum[i] <= sum[minSum.back()])
        {
            minSum.pop_back();
        }
        minSum.push_back(i);
    }
    return minLength <= n ? minLength : -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int result = a(nums, k);
    cout << result << endl;
    return 0;
}
