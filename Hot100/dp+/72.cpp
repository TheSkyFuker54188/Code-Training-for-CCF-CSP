#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    int m = word1.size(), n = word2.size();

    // dp[i][j] 表示 word1 前 i 个字符转换成 word2 前 j 个字符的最少操作数
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 初始化第一列：word1 前 i 个字符变成空串，需要 i 次删除
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;
    // 初始化第一行：空串变成 word2 前 j 个字符，需要 j 次插入
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                // 末尾字符相同，无需额外操作，直接继承左上角
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // 三种操作：
                // todo 始终在操作 word1
                //  删除 word1[i-1]：dp[i-1][j] + 1
                //*   把 word1 的最后一个字符删掉之后，剩下的子问题变成将 word1 的前 i-1 个字符转成 word2 的前 j 个字符

                //  插入 word2[j-1]：dp[i][j-1] + 1
                //*   在 word1 的末尾添加word2[j-1]，word1 的最后一个字符就和 word2 的最后一个字符相同了
                //*   之后我们可以同时忽略这两个相同的末尾字符
                //*   word1 忽略新插入的字符后，恢复成原来的前 i 个字符；
                //*   word2 忽略最后一个字符后，变成前 j-1 个字符（索引 0 ~ j-2）
                //*   剩下的子问题：将 word1 的前 i 个字符转成 word2 的前 j-1 个字符

                //  替换 word1[i-1] -> word2[j-1]：dp[i-1][j-1] + 1
                //*   直接将 word1 的最后一个字符改成 word2 的最后一个字符
                //*   现在两个末尾字符完全相同，可以同时忽略
                //*   word1 的前 i 个字符变成前 i-1 个字符（索引 0 ~ i-2）
                //*   word2 的前 j 个字符变成前 j-1 个字符（索引 0 ~ j-2）
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}