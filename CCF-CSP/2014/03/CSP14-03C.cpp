#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string pattern;
int n;

int type[27]; // 没出现:0（也就是不合法选项）   有参数:1    无参数:-1

int main()
{
    cin >> pattern;
    for (int i = 0; i < pattern.length(); i++)
    {
        if (pattern[i])
        {
            if (pattern[i + 1] == ':')
            {
                type[pattern[i] - 'a' + 1] = 1;
                i++;
            }
            else
                type[pattern[i] - 'a' + 1] = -1;
        }
    }

    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++)
    {
        string arg[27];

        string tmp;
        getline(cin, tmp);
        stringstream ss(tmp);

        ss >> tmp;        // 先倒掉没用的工具项
        while (ss >> tmp) // 只要没倒干净，就继续读
        {
            if (tmp.length() == 2 &&
                tmp[0] == '-')
            {
                int idx = tmp[1] - 'a' + 1;

                if (type[idx] == 0)
                    break;
                else if (type[idx] == -1)
                    arg[tmp[1] - 'a' + 1] = " ";
                else if (type[idx] == 1)
                {
                    if (ss >> tmp) //! 要检查!
                        arg[idx] = tmp;
                    else
                        break; // 缺参数
                }
                else
                    break;
            }
            else
                break;
        }

        cout << "Case " << i << ":";
        for (int k = 1; k <= 26; k++)
        {
            if (type[k] == -1 && arg[k] != "")
                cout << " -" << char(k + 'a' - 1);
            else if (type[k] == 1 && arg[k] != "")
                cout << " -" << char(k + 'a' - 1) << " " << arg[k];
        }
        cout << endl;
    }
}