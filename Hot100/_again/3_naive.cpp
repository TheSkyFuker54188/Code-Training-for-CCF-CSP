#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    unordered_map<char, int> a;
    //                , last_idx

    int n = s.size();

    int ans = 1;

    int l = 0;
    int r = 0;
    a[s[l]] = l;
    while (l <= r && r + 1 < n)
    {
        r++;
        if (a.find(s[r]) != a.end())
        {
            l = max(a[s[r]] + 1, l); //! 左边界可能会不小心反而向左扩展，所以要加max取缩
        }
        a[s[r]] = r;
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}