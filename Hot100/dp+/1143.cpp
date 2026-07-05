/*
找公共子序列，其实可以把他看作：
从text1中删除若干个字符，再从text2中删除若干个字符
要求剩下的字符所形成的字符串恰好相等，且长度最长
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string text1, text2;
    cin >> text1 >> text2;
    int n = text1.size(), m = text2.size();

    // dp[i][j] 表示 text1 前 i 个字符 与 text2 前 j 个字符 的 LCS 长度
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {                                     // 考虑两个末尾字符
            if (text1[i - 1] == text2[j - 1]) // 相等
            {                                 // 匹配长度增加
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else // 不相等
            {    // 放弃其中一个，取两种情况中较大的
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}