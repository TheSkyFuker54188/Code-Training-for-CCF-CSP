#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;
int n;
int cnt;

int h[MAX];

int main()
{
    // freopen("in.txt", "r", stdin);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; j++)
            h[j]++;
    }
    for (int i = 1; i <= n; i++)
    {
        int c, d;
        cin >> c >> d;
        for (int j = c; j < d; j++)
            h[j]++;
    }

    for (int i = 1; i < MAX; i++)
        if (h[i] == 2)
            cnt++;
    cout << cnt;
}