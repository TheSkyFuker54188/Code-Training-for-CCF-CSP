#include <iostream>
#include <vector>
#include <string>
/*
! 错误思路：一边扫描一边匹配 ———— 贪心
从头扫描 s[:i]，一旦发现 s[:i] 是字典里的一个单词，
就把指针 ptr 移到 i，然后从 ptr+1 开始继续往后找下一个单词。
这本质是一种贪心策略 ———— 可能导致错判
! 切掉一个单词后，剩下的字符串可能本来可以通过另一种切分被拼出，但在当前贪心选择下，剩下的字符串无法被任何单词组合覆盖

? 正确思路：
todo  动态规划并不在扫描过程中做任何“决定”
todo  DP 的每个状态 dp[i] 是“存在性”而非“唯一路径”，它把所有可能的切分都保留了
*/
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<string> v;
    string ss;
    while (cin >> ss)
    {
        v.push_back(ss);
    }

    vector<bool> dp(n + 1, false);

    dp[0] = true;
    // s[:i]的一个分割点j字符串变成:s[:j] 和 s[j+1:i]
    for (int i = 1; i <= n; i++) // 枚举前缀长度 i，判断 s[0:i] 是否可以被拼接
    {
        for (int j = 0; j < i; j++)
        {
            for (string w : v)
            {
                if (dp[j] && //
                    w == s.substr(j, i - j))
                {
                    dp[i] = true;
                    break;
                }
            }
            if (dp[i])
                break;
        }
    }
    if (dp[n])
        cout << "true";
    else
        cout << "false";
}