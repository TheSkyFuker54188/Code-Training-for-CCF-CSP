#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if (n < 2)
    {
        cout << s << endl;
        return 0;
    }

    int maxLen = 1;
    int start = 0;
    // dp[i][j] 表示 s[i..j] 是否是回文子串
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // 所有长度为 1 的子串都是回文
    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = true;
    }

    // 按子串长度递增进行递推
    for (int L = 2; L <= n; ++L) //! 长串依赖短串，所以按长度从小到大枚举
    {
        for (int i = 0; i < n; ++i) // 枚举左边界
        {
            int j = i + L - 1; // 右边界
            if (j >= n)
                break; // 越界则退出内层循环

            if (s[i] != s[j])
            {
                dp[i][j] = false;
            }
            else
            { // 两端字符相同，内部情况决定
                if (j - i < 3)
                { // 长度 2 或 3，无内部子串或只有一个字符
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            // 如果当前子串是回文且更长，则更新答案
            if (dp[i][j] && j - i + 1 > maxLen)
            {
                maxLen = j - i + 1;
                start = i;
            }
        }
    }

    cout << s.substr(start, maxLen) << endl;
    return 0;
}