// k路递归
#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
vector<vector<int>> ans;
vector<int> cur;

int n, target;

void solve(int sum)
{
    if (sum == target)
    {
        ans.push_back(cur);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int a = nums[i];

        if (sum + a <= target)
        {
            cur.push_back(a);
            solve(sum + a);
            cur.pop_back();
        }
        else
            continue;
    }
}

int main()
{
    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    solve(0);
    for (auto i : ans)
    {
        for (int j = 0; j < i.size(); j++)
        {
            cout << i[j] << " ";
        }
        cout << '\n';
    }
}