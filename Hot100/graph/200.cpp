//? BFS求连通分量个数
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int m, n;

int main()
{
    int cnt = 0;
    cin >> m >> n;
    vector<vector<char>> a(m, vector<char>(n));
    vector<vector<bool>> b(m, vector<bool>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            b[i][j] = false;
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '1' && b[i][j] == false)
            {
                b[i][j] = true;
                cnt++;
                queue<pair<int, int>> q;
                q.push({i, j});

                while (!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int new_x = x + dx[k];
                        int new_y = y + dy[k];
                        if (new_x > -1 && new_y > -1 && new_x < n && new_y < m &&
                            a[new_y][new_x] == '1' && b[new_y][new_x] == false)
                        {
                            b[new_y][new_x] = true;
                            q.push({new_y, new_x});
                        }
                    }
                }
            }
        }
    }
    cout << cnt;
}