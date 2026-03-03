#include <iostream>

using namespace std;

const int MAXN = 1e5 + 5;
int s[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }

    if (n == 1)
    {
        cout << (s[1] >= 0 && s[1] <= 1 ? 1 : 0) << endl;
        return 0;
    }

    int ans = 0;
    for (int a1 = 0; a1 <= 1; ++a1)
    {
        for (int a2 = 0; a2 <= 1; ++a2)
        {
            if (a1 + a2 != s[1])
                continue;

            bool valid = true;
            int prev_prev = a1;
            int prev = a2;

            for (int k = 3; k <= n; ++k)
            {
                int current = s[k - 1] - prev_prev - prev;
                if (current < 0 || current > 1)
                {
                    valid = false;
                    break;
                }
                prev_prev = prev;
                prev = current;
            }

            if (valid && prev_prev + prev == s[n])
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}