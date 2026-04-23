// 2017年09月 C
// JSON查询
// 字符串大模拟
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string parse_string(const string &s, int &i)
{
    i++;
    string ret = "";
    while (i < s.length())
    {
        if (s[i] == '\\')
        {
            ret += s[i + 1];
            i += 2;
        }
        else if (s[i] == '"')
        {
            i++;
            break;
        }
        else
        {
            ret += s[i++];
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string json_str = "";
    string line;
    getline(cin, line);

    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        json_str += line;
    }

    string s = "";
    for (char c : json_str)
        if (c != ' ' && c != '\n')
            s += c;

    map<string, string> dict;
    vector<string> prefix;

    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '{')
            i++;
        else if (s[i] == '}')
        {
            if (!prefix.empty())
                prefix.pop_back();
            i++;
        }
        else if (s[i] == ',')
            i++; //* 键值对之间的分隔，跳过
        else if (s[i] == '"')
        {
            // 键 ———— 必然是一个字符串
            string key = parse_string(s, i);
            string cur_path = prefix.empty() ? key : prefix.back() + '.' + key;

            i++; //* 跳过键名和值之间的冒号 ':'

            // 值 ———— 必然是一个字符串or对象
            if (s[i] == '{') //* 值是一个对象
            {
                dict[cur_path] = "OBJECT";
                prefix.push_back(cur_path);
                i++;
            }
            else if (s[i] == '"') //* 值是一个字符串
            {
                string val = parse_string(s, i);
                dict[cur_path] = "STRING " + val;
            }
        }
        else
            i++;
    }

    for (int i = 0; i < m; i++)
    {
        string query;
        cin >> query;
        if (dict.count(query))
            cout << dict[query] << endl;
        else
            cout << "NOTEXIST" << endl;
    }

    return 0;
}