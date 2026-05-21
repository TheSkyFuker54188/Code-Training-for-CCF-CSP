// 2024-09-B 字符串变换
//? 增法（二进制分解）
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    // 字符集映射：空格(32), 数字(48-57), 大写(65-90), 小写(97-122) 共63个
    int charToIdx[128];
    memset(charToIdx, -1, sizeof(charToIdx));
    char idxToChar[63];
    int tot = 0;
    // 按顺序加入：空格 ' '
    charToIdx[' '] = tot;
    idxToChar[tot] = ' ';
    tot++;
    // 数字 '0'-'9'
    for (char c = '0'; c <= '9'; c++)
    {
        charToIdx[c] = tot;
        idxToChar[tot] = c;
        tot++;
    }
    // 大写字母 'A'-'Z'
    for (char c = 'A'; c <= 'Z'; c++)
    {
        charToIdx[c] = tot;
        idxToChar[tot] = c;
        tot++;
    }
    // 小写字母 'a'-'z'
    for (char c = 'a'; c <= 'z'; c++)
    {
        charToIdx[c] = tot;
        idxToChar[tot] = c;
        tot++;
    }
    // tot 应为 63

    // 读入初始字符串
    string tmp;
    getline(cin, tmp);
    string s;
    // 去掉首尾的 '#'
    for (int i = 1; i < tmp.length() - 1; i++)
    {
        s.push_back(tmp[i]);
    }

    int n;
    cin >> n;
    cin.ignore(); // 忽略换行

    // 初始化映射：f[i] = i
    vector<int> nxt(63);
    for (int i = 0; i < 63; i++)
        nxt[i] = i;

    // 读入 n 条规则
    for (int i = 0; i < n; i++)
    {
        getline(cin, tmp);
        char x = tmp[1], y = tmp[2];
        int u = charToIdx[x], v = charToIdx[y];
        nxt[u] = v;
    }

    // 倍增表：up[c][j] 表示 f^{2^j}(c)
    vector<vector<int>> up(63, vector<int>(31));
    for (int c = 0; c < 63; c++)
    {
        up[c][0] = nxt[c];
    }
    for (int j = 1; j < 31; j++)
    {
        for (int c = 0; c < 63; c++)
        {
            up[c][j] = up[up[c][j - 1]][j - 1];
        }
    }

    int m;
    cin >> m;
    vector<int> k(m);
    for (int i = 0; i < m; i++)
    {
        cin >> k[i];
    }

    // 处理每个查询
    for (int i = 0; i < m; i++)
    {
        int steps = k[i];
        string res;
        for (char ch : s)
        {
            int cur = charToIdx[ch];
            // 二进制分解跳转
            for (int j = 0; j < 31; j++)
            {
                if (steps & (1 << j))
                {
                    cur = up[cur][j];
                }
            }
            res.push_back(idxToChar[cur]);
        }
        // 输出带 '#' 的结果
        cout << "#" << res << "#" << endl;
    }

    return 0;
}