// 2014年09月 第C题
// 算法 + 数据结构）

#include <iostream>
#include <string>

#include <cctype>

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
    if (ul == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (str[i].find(s) != string::npos)
                cout << str[i] << endl;
        }
    }
    if (ul == 0)
    {
        string s0 = s;
        for (int j = 0; j < s0.length(); j++)
        {
            s0[j] = tolower(s0[j]);
        }

        for (int i = 0; i < n; i++)
        {
            string str0 = str[i];
            for (int k = 0; k < str0.length(); k++)
            {
                str0[k] = tolower(str0[k]);
            }
            if (str0.find(s0) != string::npos)
                cout << str[i] << endl;
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