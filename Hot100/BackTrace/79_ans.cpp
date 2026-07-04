#include <iostream>
#include <string>
#include <vector>
using namespace std;

int m, n;
vector<vector<char>> board;
vector<vector<bool>> visited;
string word;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool dfs(int y, int x, int idx)
{
    if (idx == word.size())
        return true;
    if (y < 0 || y >= m || x < 0 || x >= n)
        return false;
    if (visited[y][x] || board[y][x] != word[idx])
        return false;

    visited[y][x] = true;
    for (int k = 0; k < 4; ++k)
    {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (dfs(ny, nx, idx + 1))
            return true;
    }
    visited[y][x] = false;
    return false;
}

int main()
{
    cin >> m >> n;
    board.assign(m, vector<char>(n));
    visited.assign(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    cin >> word;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] == word[0] && dfs(i, j, 0))
            {
                cout << "true";
                return 0;
            }
    cout << "false";
    return 0;
}