#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> s(n + 1, 0);
    s[0] = 0;

    unordered_map<int, int> b;
    b[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        int x = s[i] - k; //! s[i]已知作为右边界（大），找已建hash表中的左边界
        if (b.find(x) != b.end())
        {
            cnt += b[x];
        }
        b[s[i]]++;
    }
    cout << cnt;
}