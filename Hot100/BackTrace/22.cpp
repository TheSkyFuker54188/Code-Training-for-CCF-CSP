/*
1.整体角度：整个序列的总和需要是0 ，不然就代表左右括号个数不一致，
这样不管内部实际是什么顺序，都不可能匹配的。
2.从左往右累加cnt 的过程中，任意时刻需要满足cnt >= 0 。
因为如果cnt < 0 就代表此刻前缀中右括号多于左括号，那不管后续括号是什么状态，
这个多出来的右括号都不可能得到匹配了。
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> cur;
vector<vector<int>> ans;
int n;

void solve(int idx, int cnt)
{
    if (idx == 2 * n)
    {
        if (cnt == 0)
            ans.push_back(cur);
        return;
    }
    if (cnt < 0)
        return;

    cur.push_back(1);
    solve(idx + 1, cnt + 1);
    cur.pop_back();

    cur.push_back(-1);
    solve(idx + 1, cnt - 1);
    cur.pop_back();

    return;
}
int main()
{
    cin >> n;

    solve(0, 0);

    for (auto i : ans)
    {
        for (int j = 0; j < i.size(); j++)
        {
            if (i[j] == 1)
                cout << "(";
            else
                cout << ")";
        }
        cout << '\n';
    }
    
}