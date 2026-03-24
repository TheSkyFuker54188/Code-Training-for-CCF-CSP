// 2017年03月 第C题
// 算法 + 数据结构

// Markdown
#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;
int lines;
string line[MAX];
int mark[MAX]; // 1 段落  2 无序列表

int main()
{
    freopen("in.txt", "r", stdin);
    for (int i = 0; i < MAX; i++)
    {
        string tmp;
        getline(cin, tmp);
        lines++;
        if (tmp == "\n")
        {
            string tmp2;
            getline(cin, tmp2);
            if (tmp2 == "\n")
            {
                line[i] = "\n";
                continue;
            }
            else // tmp2 != "\n"
            {
                line[i] = tmp2;
                continue;
            }
        }
        else
            line[i] = tmp;

        if (1) // 区块间
        {
            if (line[i].find('#')) // 标题 <h>
            {
                int cnt = 1;
                int pos = line[i].find('#');
                while (line[i][++pos] == '#')
                    cnt++;
                string lev = to_string(cnt);
                string a = "<h" + lev + ">";
                string b = "</h" + lev + ">";

                line[i] = a + line[i] + b;
            }
            if (line[i].find('*')) // 无序列表 <li>
            {
                mark[i] = 2;
                line[i] = "<li>" + line[i] + "</li>";
            }
        }
        else // 区块内
        {
            if (line[i].find('_') != line[i].rfind('_')) // 强调
            {
                mark[i] = 1;
                int posL = line[i].find('_');
                int posR = line[i].rfind('_');
                line[i].replace(posL, 0, "<em>");
                line[i].replace(posR, 0, "</em>");
            }
            if (line[i].find('[') && line[i].find(']')) // 超级链接
            {
                mark[i] = 1;
                int TextL = line[i].find('[');
                int TextR = line[i].find(']');
                int LinkL = TextR + 1;
                int LinkR = line[i].find(')', LinkL);
                string text = line[i].substr(TextL, TextR - TextL - 1);
                string link = line[i].substr(LinkL, LinkR - LinkL - 1);
                string repl = "<a href=" + '"' + link + '"' + '>' + text + "</a>";
                line[i].replace(TextL, LinkR - TextL, repl);
            }
        }
    }

    for (int i = 0; i <= lines; i++)
    {
        if (mark[i] == 1 && line[i - 1] == "\n")
            line[i] = "<p>" + line[i];
        if (mark[i] == 1 && line[i + 1] == "\n")
            line[i] = line[i] + "</p>";

        if (mark[i] == 2 && line[i - 1] == "\n")
            line[i - 1] = "<ul>";
        if (mark[i] == 2 && line[i + 1] == "\n")
            line[i + 1] = "</ul>";
    }

    for (int i = 0; i <= lines; i++)
    {
        if (line[i] != "\n")
            cout << line[i] << endl;
    }
    return 0;
}