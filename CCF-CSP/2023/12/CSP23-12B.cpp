// 2023-12-B 因子化简
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    int q; // 查询个数
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        ll n;
        int k;
        cin >> n >> k;

        ll tmp = n;
        ll ans = 1;

        for (ll j = 2; j * j <= tmp; j++)
        {
            int cnt = 0;
            while (tmp % j == 0)
            {
                tmp /= j;
                cnt++;
            }
            if (cnt >= k)
                for (int k = 0; k < cnt; k++)
                    ans *= j;
        }

        if (tmp != 1 && k == 1)
            ans *= tmp;

        cout << ans << "\n";
    }
}