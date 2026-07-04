#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> ans;
vector<string> cur;

vector<bool> col;
vector<bool> mainDiag;
vector<bool> antiDiag;
int n;

void solve(int idx)
{ // index 表示当前要放第几行的皇后
    if (idx == n)
    {
        ans.push_back(cur);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        int y = idx;
        int x = j;

        int main = x - y + n - 1;
        int anti = x + y;

        if (col[x] == false && mainDiag[main] == false && antiDiag[anti] == false)
        {
            cur[y][x] = 'Q';
            col[x] = true;
            mainDiag[main] = true;
            antiDiag[anti] = true;

            solve(idx + 1);

            cur[y][x] = '.';
            col[x] = false;
            mainDiag[main] = false;
            antiDiag[anti] = false;
        }
    }
}
int main()
{
    cin >> n;
    string b = "";

    cur.assign(n, string(n, '.'));
    col.assign(n, false);
    mainDiag.assign(2 * n - 1, false);
    antiDiag.assign(2 * n - 1, false);

    solve(0);

    for (auto i : ans)
    {
        for (int j = 0; j < i.size(); j++)
        {
            cout << i[j] << '\n';
        }
        cout << '\n';
    }
}