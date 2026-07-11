#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> edge(n);
    // vector<int> edge(n, -1);
    vector<int> in(n, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[b].push_back(a);
        in[a]++;
    }

    vector<int> q;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            q.push_back(i);
            cnt++;
        }
    }

    while (q.empty() != true)
    {
        int from = q.back();
        q.pop_back();
        for (int i : edge[from])
        {
            in[i]--;
            if (in[i] == 0)
            {
                q.push_back(i);
                cnt++;
            }
        }
    }
    if (cnt != n)
    {
        cout << "false";
        return 0;
    }
    cout << "true";
    return 0;
}