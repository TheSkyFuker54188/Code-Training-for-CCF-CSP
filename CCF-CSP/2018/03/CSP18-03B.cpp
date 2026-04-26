// 2018年03月 B 碰撞的小球
// 算法 + 数据结构）

#include <iostream>

using namespace std;

struct Ball
{
    int pos;
    int velocity = 1; // 向右为+1 向左为-1
};

int n, L, t;

int main()
{
    cin >> n >> L >> t;

    Ball ball[n];
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        ball[i].pos = tmp;
    }

    for (int tick = 1; tick <= t; tick++)
    {
        for (int id = 0; id < n; id++)
        {
            if ((ball[id].pos == L && ball[id].velocity == 1) // 撞墙
                || (ball[id].pos == 0 && ball[id].velocity == -1))
                ball[id].velocity = 0 - ball[id].velocity;

            for (int another = 0; another < n; another++) // 撞球
            {
                if (another == id)
                    continue;
                if (ball[id].pos == ball[another].pos)
                {
                    ball[id].velocity = 0 - ball[id].velocity;
                    ball[another].velocity = 0 - ball[another].velocity;
                    break;
                }
            }
            ball[id].pos += ball[id].velocity;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << ball[i].pos;
        else
            cout << ball[i].pos << " ";
    }
    return 0;
}