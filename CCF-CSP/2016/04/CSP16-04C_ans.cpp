// 2016年04月 C
// 路径解析
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);

    stack<string> dir;
    string now;
    int p;
    cin >> p;
    cin.ignore();
    getline(cin, now);

    // 解析当前路径到stack
    if (now[0] == '/')
        dir.push("root");
    int pos = 0;
    while (pos < now.length())
    {
        int next;
        if (now[pos] == '/')
            pos++; // 跳过开头的斜杠

        if (pos >= now.length())
            break;

        next = now.find('/', pos);
        if (next == string::npos)
        {
            next = now.length();
        }

        string token = now.substr(pos, next - pos);
        dir.push(token);
        pos = next;
    }
    /* 读取解析正确性检验
    while (dir.size() != 0)
    {
        string debug = dir.top();
        dir.pop();
        cout << "DEBUG " << debug << endl;
    } */

    for (int i = 0; i < p; i++)
    {
        string line;
        getline(cin, line);

        stack<string> tmp;

        if (line[0] == '/') //* 从根开始
        {
            if (line[0] == '/')
                tmp.push("root");
            int pos1 = 0;
            while (pos1 < line.length())
            {
                while (pos1 < line.length() && line[pos1] == '/')
                    pos1++; // 跳过开头的斜杠

                if (pos1 >= line.length())
                    break;

                int next;

                next = line.find('/', pos1);
                if (next == string::npos)
                {
                    next = line.length();
                }

                string token = line.substr(pos1, next - pos1);

                // 处理 . 和 .. 和 普通token
                if (token == "..")
                {
                    if (!tmp.empty() && tmp.top() != "root")
                    {
                        tmp.pop();
                    }
                }
                else if (token == ".")
                {
                    // ignore
                }
                else if (token != "")
                {
                    tmp.push(token);
                }

                pos1 = next;
            }
        }

        else // line[0]=='.' //* 从当前目录开始
        {
            tmp = dir;
            int pos2 = 0;
            while (pos2 < line.length())
            {
                int next;

                // --- 修复点：对于以目录名开头的相对路径，跳过所有的斜杠提取是不正确的。
                // 而是应该先直接去尝试寻找 `/` 作为终止符。

                while (pos2 < line.length() && line[pos2] == '/')
                    pos2++; // 跳过多余的开头的斜杠

                if (pos2 >= line.length())
                    break;

                next = line.find('/', pos2);
                if (next == string::npos)
                {
                    next = line.length();
                }

                string token = line.substr(pos2, next - pos2);

                // 处理 . 和 .. 和 普通token
                if (token == "..")
                {
                    if (!tmp.empty() && tmp.top() != "root")
                    {
                        tmp.pop();
                    }
                }
                else if (token == ".")
                {
                    // ignore
                }
                else if (token != "")
                {
                    tmp.push(token);
                }

                pos2 = next;
            }
        }

        stack<string> output;
        while (tmp.size() != 0)
        {
            string a = tmp.top();
            if (a != "root")
                output.push(a);
            tmp.pop();
        }

        if (output.size() == 0)
            cout << "/";
        while (output.size() != 0)
        {
            if (output.top() != "")
                cout << "/" << output.top();
            output.pop();
        }
        cout << endl;
    }
    return 0;
}