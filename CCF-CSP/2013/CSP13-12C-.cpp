#include <iostream>

using namespace std;

int main()
{
    int n, i, j;
    long long max;

    cin >> n;

    long long s, ans = n;
    int h[n];

    for (i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (i = 0; i < n; i++)
    {
        max = h[i];
        for (j = i; j < n; j++)
        {
            if (h[j] < max)
            {
                max = h[j];
            }
            s = max * (j - i + 1);
            if (s > ans)
                ans = s;
        }
    }
    cout << ans;
}