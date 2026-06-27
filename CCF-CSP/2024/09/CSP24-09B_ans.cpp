// 2024-09-B 字符串变换
//? 倍增法（二进制分解）
#include <iostream>
#include <string>
#include <vector>
#include <cstring> // 用于 memset
using namespace std;

int main()
{
    // ========== 1. 建立字符与数字下标的双向映射 ==========
    // 我们共有63种字符：' ', '0'..'9', 'A'..'Z', 'a'..'z'
    //? 一对双向映射表: 离散变为了连续（集中在63个存储单位中）
    int charToIdx[128];                       // ASCII范围 0~127，大多数用不到
    memset(charToIdx, -1, sizeof(charToIdx)); // 初始化为 -1
    char idxToChar[63];                       // 下标 -> 字符

    int tot = 0; // 当前已登记字符数

    // 先加入空格
    charToIdx[' '] = tot;
    idxToChar[tot] = ' ';
    tot++;

    // 加入数字 '0'~'9'
    for (char c = '0'; c <= '9'; c++)
    {
        charToIdx[c] = tot;
        idxToChar[tot] = c;
        tot++;
    }

    // 加入大写字母 'A'~'Z'
    for (char c = 'A'; c <= 'Z'; c++)
    {
        charToIdx[c] = tot;
        idxToChar[tot] = c;
        tot++;
    }

    // 加入小写字母 'a'~'z'
    for (char c = 'a'; c <= 'z'; c++)
    {
        charToIdx[c] = tot;
        idxToChar[tot] = c;
        tot++;
    }
    // tot 现在应该是 1 + 10 + 26 + 26 = 63

    // ========== 2. 读入初始字符串 s ==========
    string tmp;
    getline(cin, tmp); // 读入整行，例如 #Hello World#
    string s;
    // 掐掉首尾的 '#'，取出中间的真正字符串
    for (int i = 1; i < tmp.length() - 1; i++)
    {
        s.push_back(tmp[i]);
    }

    // ========== 3. 读入变换规则 ==========
    int n;
    cin >> n;
    cin.ignore(); // 忽略 cin 后残留的换行符，以便后续 getline 正常工作

    // 初始化 f 映射：对于每个字符，默认都映射为自己
    vector<int> nxt(63);
    for (int i = 0; i < 63; i++)
    {
        nxt[i] = i; // 未定义的规则将保持不变
    }

    // 读入 n 条规则，每条形如 #xy#，表示 f(x) = y
    for (int i = 0; i < n; i++)
    {
        getline(cin, tmp); // 例如 "#e #"
        char x = tmp[1];   // 第 1 个字符（跳过开头的#）
        char y = tmp[2];   // 第 2 个字符
        int u = charToIdx[x];
        int v = charToIdx[y];
        //? charToIdx 把字符转为索引，方便存进 nxt 数组
        nxt[u] = v; // f(x) = y
    }

    // ========== 4. 构建倍增表 up ==========
    // up[c][j] 表示：对字符 c 应用 f 共 2^j 次后得到的字符
    vector<vector<int>> up(63, vector<int>(31));

    // j = 0 的情况，就是变换 1 次（2^0 = 1）
    for (int c = 0; c < 63; c++)
    {
        up[c][0] = nxt[c];
    }

    // 从 j = 1 到 30 递推
    for (int j = 1; j < 31; j++)
    {
        for (int c = 0; c < 63; c++)
        {
            int mid = up[c][j - 1];    // 先走 2^(j-1) 步
            up[c][j] = up[mid][j - 1]; // 再走 2^(j-1) 步
        }
    }

    // ========== 5. 处理查询 ==========
    int m;
    cin >> m;
    vector<int> queries(m);
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i];
    }

    // 逐个查询处理
    for (int i = 0; i < m; i++)
    {
        int k = queries[i]; // 需要变换的次数
        string result;
        // 对原字符串 s 的每一个字符分别进行 k 次变换
        for (char ch : s)
        {
            int cur = charToIdx[ch]; // 字符 -> 编号
            // 二进制分解 k，按位跳转
            for (int j = 0; j < 31; j++)
            {
                if (k & (1 << j))
                {                     // 如果 k 的第 j 位是 1
                    cur = up[cur][j]; // 应用 2^j 次变换
                }
            }
            result.push_back(idxToChar[cur]); // 编号 -> 字符，追加到结果串
        }
        // 按照题目要求，输出用 # 括起来的结果
        cout << "#" << result << "#" << endl;
    }

    return 0;
}