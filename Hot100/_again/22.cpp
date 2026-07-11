#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ans;
int sum;

void solve(int idx)
{
    if (idx == 2 * n)
    {
        if (sum == 0)
        {
            for (int i : ans)
            {
                if (i == 1)
                    cout << '(';
                else
                    cout << ')';
            }
            cout << '\n';
        }
        return;
    }
    if (sum < 0)
        return;

    sum++;
    ans.push_back(1);
    solve(idx + 1);
    ans.pop_back();
    sum--;

    sum--;
    ans.push_back(-1);
    solve(idx + 1);
    ans.pop_back();
    sum++;
}

int main()
{
    cin >> n;
    solve(0);
}