#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
vector<int> cur;
vector<vector<int>> ans;
int n;

void solve(int idx)
{
    if (idx == n)
    {
        ans.push_back(cur);
        return;
    }

    // A.选
    cur.push_back(nums[idx]);
    solve(idx + 1);

    // 回溯
    cur.pop_back();

    // B.不选
    solve(idx + 1);
}

int main()
{
    int x;
    while (cin >> x)
    {
        nums.push_back(x);
    }
    n = nums.size();

    solve(0);

    for (auto i : ans)
    {
        int d = i.size();
        for (int j = 0; j < d; j++)
        {
            cout << i[j] << " ";
        }
        cout << '\n';
    }

    return 0;
}