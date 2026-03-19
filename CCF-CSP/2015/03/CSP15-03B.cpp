// 2015年03月 第B题
// 算法 + 数据结构）

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1 + 1000;
int n;

struct num
{
    int id;
    int cnt = 0;
};

num s[MAX];

bool cmp(num a, num b)
{
    if (a.cnt != b.cnt)
    {
        return a.cnt > b.cnt;
    }
    else
    {
        return a.id < b.id;
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < MAX; i++)
    {
        s[i].id = i;
    }

    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        s[val].cnt++;
    }

    sort(s, s + MAX, cmp);

    for (int i = 0; i < MAX; i++)
    {
        if (s[i].cnt != 0)
        {
            cout << s[i].id << " " << s[i].cnt << endl;
        }
        else
            break;
    }
}