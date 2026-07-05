#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> dp(n, 0); // dp[i] 表示以 i 结尾的最长有效括号子串长度
    // dp[0] 默认为 0，因为单个字符不可能有效

    for (int i = 1; i < n; ++i)
    {
        if (s[i] == '(')
        {
            dp[i] = 0; // 以 '(' 结尾不可能有效
        }
        else
        {
            // s[i] == ')'
            int inner_len = dp[i - 1]; // 中间有效部分的长度
            int j = i - inner_len - 1; // todo  j：可能匹配的 '(' 的位置
            // dp[i-1] 代表以 i-1 结尾的已经配对好的一坨，我们把它整体忽略掉，找这一坨左边紧挨着的那个字符
            if (j < 0 || s[j] == ')')
            {
                dp[i] = 0; // 无法匹配
            }
            else
            { // 如果 j 位置的字符是 '('，那么它就能和 i 位置的 ')' 配对，形成一个更大的有效串：'(' + 有效部分 + ')'
                // 新的长度 = 有效部分的长度 + 2   '(' + 有效部分 + ')'
                dp[i] = inner_len + 2;
                if (j - 1 >= 0)//j-1 是左括号再往左一个字符。那里有可能藏着之前的合法括号子串
                {
                    dp[i] += dp[j - 1];
                }
            }
        }
    }

    int ans = 0;
    for (int x : dp)
    {
        ans = max(ans, x);
    }
    cout << ans << endl;

    return 0;
}