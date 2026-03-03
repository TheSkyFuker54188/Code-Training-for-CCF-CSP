#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

string s, t;
int len;
stack<char> sta;
vector<char> ans;
void dfs(int i, int j)
{
    if (i == len && j == len)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    if (i < len)
    {
        sta.push(s[i]);
        ans.push_back('i');
        dfs(i + 1, j);
        sta.pop();
        ans.pop_back();
    }
    if (j < i && j < len && sta.top() == t[j])
    {
        char tmp = sta.top();
        sta.pop();
        ans.push_back('o');
        dfs(i, j + 1);
        sta.push(tmp);
        ans.pop_back();
    }
}
int main()
{
    while (cin >> s >> t)
    {
        len = s.size();
        ans.clear();
        while (!sta.empty())
            sta.pop();
        cout << "[" << endl;
        dfs(0, 0);
        cout << "]" << endl;
    }

    return 0;
}