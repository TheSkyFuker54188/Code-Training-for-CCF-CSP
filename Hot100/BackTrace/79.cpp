#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<char>> a;
vector<vector<bool>> b;
vector<char> cur;
vector<char> s;
int m, n;
int L;
bool flag = false;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void solve(int y, int x, int l)
{
    if (flag)
        return;
    if (l == L)
    {
        if (cur == s)
        {
            cout << "true";
            flag = true;
        }
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m //
            && b[ny][nx] == false)
        {
            char c = a[ny][nx];
            if (c == s[l])
            {
                b[ny][nx] = true;
                cur.push_back(c);
                solve(ny, nx, l + 1);
                cur.pop_back();
                b[ny][nx] = false;
            }
        }
    }
}

int main()
{
    cin >> m >> n;

    a.assign(m, vector<char>(n));
    b.assign(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            b[i][j] = false;
        }

    string ss;
    cin >> ss;
    for (char c : ss)
        s.push_back(c);

    L = ss.size();

    int st = s[0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == st)
            {
                cur.push_back(st);
                b[i][j] = true;
                solve(i, j, 1);
                b[i][j] = false;
                cur.pop_back();
            }
        }
    }

    if (flag == false)
        cout << "false";
}