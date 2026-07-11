#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int l = a[i];
        int tem = 0;
        int s = 0;
        for (int j = i + 1; j < n; j++)
        {
            int r = a[j];
            if (r < l)
                tem += (l - r);
            else
            {
                i=j-1;
                s = tem;
                break;
            }
        }
        ans += s;
    }
    cout << ans;
}