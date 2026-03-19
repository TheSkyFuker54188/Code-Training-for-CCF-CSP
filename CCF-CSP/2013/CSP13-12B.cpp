// 2013年12月 第B题
// 涉及考点：算法 + 数据结构）

#include <iostream>
#include <string>

using namespace std;

int a, x = 0;
string s;

int main()
{
    cin >> s;

    int t, weight = 1;
    for (int i = 0; i < 12; i++)
    {
        if (s[i] != '-')
        {
            t = (s[i] - '0');
            x += t * (weight);
            weight++;
        }
    }

    a = s[12] - '0';
    x = x % 11;
    if (x == 10)
    {
        if (s[12] == 'X')
            cout << "Right";
        else
        {
            s[12] = 'X';
            cout << s;
        }
    }
    else
    {
        if (x == a)
            cout << "Right";
        else
        {
            s[12] = '0' + x;
            cout << s;
        }
    }
}