// 2016年04月 C
// 路径解析
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 辅助函数：根据分隔符 '/' 分割路径字符串，滤掉空字符串和 "."
vector<string> splitPath(const string &path)
{
    vector<string> tokens;
    string token;
    for (char c : path)
    {
        if (c == '/')
        {
            if (!token.empty() && token != ".")
            {
                tokens.push_back(token);
            }
            token.clear();
        }
        else
        {
            token += c;
        }
    }
    if (!token.empty() && token != ".")
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int p;
    if (!(cin >> p))
        return 0;
    string start_dir;
    cin >> start_dir;
    cin.ignore(256, '\n');

    for (int i = 0; i < p; i++)
    {
        string line;
        getline(cin, line);
        if (line.empty())
        { // 若为空字符串，结果是当前目录
            line = start_dir;
        }

        string full_path;
        if (line[0] == '/')
        {
            full_path = line;
        }
        else
        {
            // 是相对路径，拼接在当前目录之后
            full_path = start_dir + "/" + line;
        }

        vector<string> tokens = splitPath(full_path);
        vector<string> stack; // 用 vector 模拟栈，更方便最后正序输出

        for (const string &token : tokens)
        {
            if (token == "..")
            {
                if (!stack.empty())
                {
                    stack.pop_back(); // 返回上一级
                }
            }
            else
            {
                stack.push_back(token);
            }
        }

        if (stack.empty())
        {
            cout << "/" << endl;
        }
        else
        {
            for (const string &dir : stack)
            {
                cout << "/" << dir;
            }
            cout << endl;
        }
    }
    return 0;
}