// 2018年03月 第A题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

const int MAX = 30;

int a[MAX];
int s;

int main()
{
    int j = 0;
    int cnt = 0;
    while (1)
    {
        cin >> a[j];
        if (a[j] == 0)
            break;
        j++;
        cnt++;
    }

    int last = 0;
    for (int i = 0; i <= cnt; i++)
    {
        if (a[i] == 2)
        {
            if (i == 0 || a[i - 1] == 1)
            {
                last = 2;
                s += last;
                continue;
            }
            else
            {
                last += 2;
                s += last;
            }
        }
        else if (a[i] == 1)
        {
            s += 1;
            last = 1;
        }
        else if (a[i] == 0)
        {
            break;
        }
    }
    cout << s;
}