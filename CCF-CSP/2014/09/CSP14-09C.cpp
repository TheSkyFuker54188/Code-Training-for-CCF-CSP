// 2014年09月 第C题
// 涉及考点：算法 + 数据结构）

#include <iostream>
#include <string>

using namespace std;

/*
ASCII:
A~Z
65~90

a~z
97~122
*/

string s;
int n;
string str[100];
bool ul;

inline void match()
{
    int l = s.length();
    if (ul == 0) // 不敏感
    {
        for (int i = 0; i < n; i++)
        {
            int lstr = str[i].length();
            for (int j = 0; j <= lstr - l; j++)
            {
                if (str[i][j] == s[0] ||
                    abs(str[i][j] - s[0]) == 32)
                {
                    int k = 0;
                    for (k = 1; k < l; k++)
                    {
                        if (str[i][j + k] == s[k] ||
                            abs(str[i][j + k] - s[k]) == 32)
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (k == l)
                    {
                        cout << str[i] << endl;
                        break;
                    }
                }
            }
        }
    }

    else // 敏感
    {    // ul==1
        for (int i = 0; i < n; i++)
        {
            int lstr = str[i].length();
            for (int j = 0; j <= lstr - l; j++)
            {
                if (str[i][j] == s[0])
                {
                    int k = 0;
                    for (k = 1; k < l; k++)
                    {
                        if (str[i][j + k] == s[k])
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (k == l)
                    {
                        cout << str[i] << endl;
                        break;
                    }
                }
                /* if (str[i][j] == s[cnt])
                {
                    cnt++;
                    if (cnt == l)
                    {
                        cout << str[i] << endl;
                        break;
                    }
                }
                else
                {
                    cnt = 0;
                } */
            }
        }
    }
}

int main()
{
    cin >> s;
    cin >> ul;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    match();
}