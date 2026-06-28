#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    deque<int> q;

    for (int i = 0; i < n; i++)
    {
        if (!q.empty() &&
            q.front() <= i - k)
            q.pop_front();

        while (!q.empty() &&
               nums[q.back()] < nums[i])
            q.pop_back();

        q.push_back(i);

        if (i >= k - 1)
            cout << nums[q.front()] << " ";
    }
}