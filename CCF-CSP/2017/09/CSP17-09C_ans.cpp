// 2017年09月 C
// JSON查询
// 字符串大模拟
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// 用于专门获取双引号内部的字符串及转义内容
string parse_string(const string &s, int &i)
{
    i++; // 跳过起始的双引号 '"'
    string res = "";
    while (i < s.length())
    {
        if (s[i] == '\\')    //!  '\\' 在 C++ 中只代表 一个字符（即真正的物理符号 \）
        {                    //* 观察题目要求：
                             //* 只要遇到反斜杠 \，我们只需要忽略这个反斜杠，把反斜杠紧跟着的下一个字符原样保留下来就可以了
            res += s[i + 1]; // 遇到反斜杠转义，直接拼入下一个字符
            i += 2;
        }
        else if (s[i] == '"')
        {
            i++; // 遇到结束的双引号 '"'
            break;
        }
        else
        {
            res += s[i++];
        }
    }
    return res;
}

int main()
{
    // 提升IO读取效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    string json_str = "";
    string line;
    getline(cin, line); //! 读取第一行剩下的换行符

    // 读取所有的文件并直接追加
    for (int i = 0; i < n; ++i)
    {
        getline(cin, line);
        json_str += line;
    }

    // 预处理：题目说明字符串里没有空格，所有的空字符全都是为了缩紧的美观字符，所以直接删除即可
    string s = "";
    for (char c : json_str)
    {
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r')
        {
            s += c;
        }
    }

    map<string, string> dict;
    vector<string> prefix;

    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '{')
        {
            i++; // 最外层对象的开始
        }
        else if (s[i] == '}')
        {
            // 退出当前层级对象
            if (!prefix.empty())
            {
                prefix.pop_back();
            }
            i++;
        }
        else if (s[i] == ',')
        {
            i++; // 键值对之间的分隔，跳过
        }
        else if (s[i] == '"')
        {
            // 1. 获取键名 Key
            string key = parse_string(s, i);

            i++; // 跳过键名和值之间的冒号 ':'

            // 计算当前的绝对路径
            string cur_path = prefix.empty() ? key : prefix.back() + "." + key;

            // 2. 获取值 Value
            if (s[i] == '{')
            {
                // 如果值是一个对象，则标记并在路径中进一阶层
                dict[cur_path] = "OBJECT";
                prefix.push_back(cur_path);
                i++; // 跳过 '{'
            }
            else if (s[i] == '"')
            {
                // 如果值是一个字符串直接写入结果
                string val = parse_string(s, i);
                dict[cur_path] = "STRING " + val;
            }
        }
        else
        {
            i++;
        }
    }

    // 处理 m 次查询
    for (int k = 0; k < m; ++k)
    {
        string query;
        cin >> query;
        if (dict.count(query))
        { //* 找字典中有几个指定的 key
            //* 如果 query 不存在于字典中，返回 0
            // 根据要求，如果是字符串不用加双引号，只加 STRING。我们已经存入时准备好了前缀。
            cout << dict[query] << "\n";
        }
        else
        {
            cout << "NOTEXIST\n";
        }
    }

    return 0;
}