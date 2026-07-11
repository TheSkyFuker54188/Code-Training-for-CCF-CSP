#include <iostream>
#include <vector>
#include <string>

using namespace std;

int m, n;
bool flag = false;
vector<char> word;
vector<vector<char>> a;
vector<vector<bool>> b;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

vector<char> ans;

void solve(int y, int x)
{
    if (flag)
        return;
    if (ans.size() == word.size())
    {
        if (ans == word)
        {
            flag = true;
            cout << "true";
            return;
        }
        else
        {
            return;
        }
    }
    int idx = ans.size();
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < m && nx >= 0 && nx < n && //
            a[ny][nx] == word[idx])
        {
            ans.push_back(a[ny][nx]);
            b[ny][nx] = true;
            solve(ny, nx);
            ans.pop_back();
            b[ny][nx] = false;
        }
    }
}

int main()
{
    cin >> m >> n;
    a.resize(m, vector<char>(n));
    b.assign(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    string s;
    cin >> s;
    for (char c : s)
        word.push_back(c);

    char start = s[0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == start)
            {
                ans.push_back(start);
                b[i][j] = true;
                solve(i, j);
                b[i][j] = false;
                ans.pop_back();
            }
            else
                continue;
        }
    }
    if (!flag)
        cout << "false";
}