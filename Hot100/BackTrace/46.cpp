#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<bool> used;
vector<int> cur;
int n;

void solve(int idx) // 当前已经填好的数字个数，或者下一个要填的位置的索引
{                   // 不是当前正在填的位置的索引
    if (idx == n)
    {
        for (int i = 0; i < n; i++)
            cout << cur[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] == false)
        {
            cur.push_back(nums[i]);
            used[i] = true;
            solve(idx + 1);
            cur.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    int x;
    while (cin >> x)
    {
        nums.push_back(x);
    }
    n = nums.size();

    sort(nums.begin(), nums.end());
    used.assign(n, false);
    solve(0);

    return 0;
}