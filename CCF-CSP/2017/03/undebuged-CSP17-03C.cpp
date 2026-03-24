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
        if (tmp == "") // 读到\n 抛弃之，存为空串
        {
            lines--;
            string tmp_next;
            getline(cin, tmp_next);
            lines++;
            if (tmp_next == "")
            {
                lines--;
                break;
            }
            else
            {
                line[i] = tmp_next;
                cout << "\nDEBUG: " << "line" << i << ": " << line[i] << "\n";
                continue;
            }
        }
        else
            line[i] = tmp;

        cout << "\nDEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
    }
    for (int i = 0; i < lines; i++)
    {
        // 区块间
        {
            mark[i] = 1;
            if (line[i].find('#') != string::npos) // 标题 <h>
            {
                mark[i] = 0;
                int cnt = 1;
                int pos = line[i].find('#');
                while (line[i][++pos] == '#')
                    cnt++;
                string lev = to_string(cnt);
                string a = "<h" + lev + ">";
                string b = "</h" + lev + ">";
                line[i].replace(--pos, cnt + 1, a);
                line[i] = line[i] + b;

                cout << "\nDEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
            }
            if (line[i].find('*') != string::npos) // 无序列表 <li>
            {
                mark[i] = 2;
                line[i].replace(0, 2, "<li>");
                line[i] = line[i] + "</li>";

                cout << "\nDEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
            }
        }
        // 区块内
        {
            if (line[i].find('_') != line[i].rfind('_')) // 强调
            {
                int posL = line[i].find('_');
                int posR = line[i].rfind('_');
                line[i].replace(posL, 1, "<em>");
                line[i].replace(posR, 1, "</em>");

                cout << "\nDEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
            }
            if (line[i].find('[') != string::npos && line[i].find(']') != string::npos) // 超级链接
            {
                int TextL = line[i].find('[');
                int TextR = line[i].find(']');
                int LinkL = TextR + 1;
                int LinkR = line[i].find(')', LinkL);
                string text = line[i].substr(TextL, TextR - TextL - 1);
                string link = line[i].substr(LinkL, LinkR - LinkL - 1);
                string repl = "<a href=" + '"' + link + '"' + '>' + text + "</a>";
                line[i].replace(TextL, LinkR - TextL, repl);

                cout << "\nDEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
            }
        }
    }

    for (int i = 0; i < lines; i++)
    {
        if ((mark[i] == 1 && i == 0) || (mark[i] == 1 && mark[i - 1] != 1))
            line[i] = "<p>" + line[i];
        if (mark[i] == 1 && mark[i + 1] != 1)
            line[i] = line[i] + "</p>";

        if ((mark[i] == 2 && i == 0) || (mark[i] == 2 && mark[i - 1] != 2))
            line[i] = "<ul>\n" + line[i];
        if (mark[i] == 2 && mark[i + 1] != 2)
            line[i] = line[i] + "\n</ul>";

        cout << "\nDEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
    }

    for (int i = 0; i < lines; i++)
    {
        cout << line[i] << endl;
    }
    return 0;
}