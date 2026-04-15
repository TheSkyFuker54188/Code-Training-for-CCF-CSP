// 2016年04月 C
// 路径解析
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);

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
                while (line[pos1] == '/')
                    pos1++; // 跳过开头的斜杠

                if (pos1 >= line.length())
                    break;

                int next;
                //* 处理 .类 操作
                if ((line[pos1] == '.' && line[pos1 + 1] == '.') // .. （上一级目录）
                    && (line[pos1 + 2] == '/' || pos1 + 2 >= line.length()))
                {
                    // cout << "DEBUG " << tmp.top() << endl
                    //<< "pop\n";
                    if (tmp.top() != "root")
                        tmp.pop();
                    // cout << "DEBUG " << tmp.top() << endl;
                    pos1 += 3;
                }
                else if (line[pos1] == '.' &&
                         (line[pos1 + 1] == '/' || pos1 + 1 >= line.length())) // ./ （当前目录）
                {
                    pos1 += 2;
                }
                if (pos1 >= line.length())
                    break;
                //* 处理普通

                next = line.find('/', pos1);
                if (next == string::npos)
                {
                    next = line.length();
                }

                string token = line.substr(pos1, next - pos1);
                // cout << "DEBUG " << token << endl;
                if (token != ".." && token != "." && token != "")
                    tmp.push(token);
                pos1 = next;
            }
        }

        else // line[0]=='.' //* 从当前目录开始
        {
            tmp = dir;
            int pos2 = 0;
            while (pos2 < line.length())
            {
                while (line[pos2] == '/')
                    pos2++; // 跳过开头的斜杠
                int next;
                //* 处理 .类 操作
                if ((line[pos2] == '.' && line[pos2 + 1] == '.') // .. （上一级目录）
                    && (line[pos2 + 2] == '/' || pos2 + 2 >= line.length()))
                {
                    // cout << "DEBUG " << tmp.top() << endl
                    //  << "pop\n";
                    if (tmp.top() != "root")
                        tmp.pop();
                    // cout << "DEBUG " << tmp.top() << endl;
                    pos2 += 3;
                }
                else if (line[pos2] == '.' && // ./ （当前目录）
                         (line[pos2 + 1] == '/' || pos2 + 1 >= line.length()))
                {
                    pos2 += 2;
                }
                if (pos2 >= line.length())
                    break;

                //* 处理普通
                while (line[pos2] == '/')
                    pos2++; // 跳过开头的斜杠

                if (pos2 >= line.length())
                    break;

                next = line.find('/', pos2);
                if (next == string::npos)
                {
                    next = line.length();
                }

                string token = line.substr(pos2, next - pos2);
                cout << "DEBUG " << token <<"【"<< endl;
                if (token != ".."   //
                    && token != "." //
                    && token != "")
                    tmp.push(token);
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