// 2017年03月 第C题
// 算法 + 数据结构

// Markdown
#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;
string line[MAX];
int mark[MAX]; // 1 段落  2 无序列表

int main()
{
    //freopen("in.txt", "r", stdin);
    int lines = 0;
    string tmp;
    while (lines < MAX && getline(cin, tmp)) //! 以 EOF 为终止条件，天然等于“实际有效输入
    {
        line[lines++] = tmp;
    }

    for (int i = 0; i < lines; i++)
    {
        // 区块间
        {
            if (line[i].empty())
                mark[i] = 0;
            else
                mark[i] = 1;

            if (!line[i].empty() && line[i][0] == '#') // 标题 <h>
            {
                mark[i] = 0;
                int cnt = 1;
                int tmp_pos = 0;
                while (tmp_pos + 1 < static_cast<int>(line[i].size()) && line[i][tmp_pos + 1] == '#')
                {
                    cnt++;
                    tmp_pos++;
                }
                int textStart = cnt;
                while (textStart < static_cast<int>(line[i].size()) && line[i][textStart] == ' ')
                    textStart++;
                string lev = to_string(cnt);
                string a = "<h" + lev + ">";
                string b = "</h" + lev + ">";
                line[i].replace(0, textStart, a);
                line[i] = line[i] + b;

                // cout << "DEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
            }
            if (!line[i].empty() && line[i][0] == '*') // 无序列表 <li>
            {
                int textStart = 1;
                while (textStart < static_cast<int>(line[i].size()) && line[i][textStart] == ' ')
                    textStart++;
                mark[i] = 2;
                line[i].replace(0, textStart, "<li>");
                line[i] = line[i] + "</li>";

                // cout << "DEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
            }
        }
        // 区块内
        {
            if (line[i].find('_') != string::npos) // 强调
            {
                string transformed;
                transformed.reserve(line[i].size());
                bool inEm = false;
                for (int j = 0; j < static_cast<int>(line[i].size()); j++)
                {
                    if (line[i][j] == '_')
                    {
                        transformed += (inEm ? "</em>" : "<em>");
                        inEm = !inEm;
                    }
                    else
                    {
                        transformed += line[i][j];
                    }
                }
                line[i] = transformed;

                // cout << "DEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
            }
            if (line[i].find('[') != string::npos && line[i].find(']') != string::npos) // 超级链接
            {
                size_t searchPos = 0;
                while (searchPos < line[i].size())
                {
                    size_t textL = line[i].find('[', searchPos);
                    if (textL == string::npos)
                        break;

                    size_t textR = line[i].find(']', textL + 1);
                    if (textR == string::npos)
                        break;

                    if (textR + 1 >= line[i].size() || line[i][textR + 1] != '(')
                    { // 越界 or 有[]无紧邻(
                        searchPos = textR + 1;
                        continue;
                    }

                    size_t linkR = line[i].find(')', textR + 2);
                    if (linkR == string::npos)
                        break;

                    string text = line[i].substr(textL + 1, textR - textL - 1);
                    string link = line[i].substr(textR + 2, linkR - textR - 2);
                    string repl = "<a href=\"" + link + "\">" + text + "</a>";
                    line[i].replace(textL, linkR - textL + 1, repl);

                    searchPos = textL + repl.size();
                }

                // cout << "DEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
            }
        }
    }

    for (int i = 0; i < lines; i++)
    {
        if ((mark[i] == 1 && i == 0) || (mark[i] == 1 && mark[i - 1] != 1))
        {
            line[i] = "<p>" + line[i];
            // cout << "DEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
        }
        if (mark[i] == 1 && (i == lines - 1 || mark[i + 1] != 1))
        {
            line[i] = line[i] + "</p>";
            // cout << "DEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
        }

        if ((mark[i] == 2 && i == 0) || (mark[i] == 2 && mark[i - 1] != 2))
        {
            line[i] = "<ul>\n" + line[i];
            // cout << "DEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
        }
        if (mark[i] == 2 && (i == lines - 1 || mark[i + 1] != 2))
        {
            line[i] = line[i] + "\n</ul>";
            // cout << "DEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
        }

        // cout << "DEBUG: " << "line" << i << ": " << line[i] << "\n"; //!
    }

    for (int i = 0; i < lines; i++)
    {
        if (!line[i].empty())
            cout << line[i] << endl;
    }
    return 0;
}

/*
你接下来最该补的 CSP 能力

字符串解析基本功：find、substr、区间边界（左闭右开）与“先判界再访问”。
状态机思维：开关状态（如 inEm）与“扫描指针 i/j”。
分层设计：输入层（读到 EOF）/区块层/行内层分开写，减少互相污染。
复杂度意识：尽量单遍扫描，避免反复全串替换导致逻辑错位。 
*/