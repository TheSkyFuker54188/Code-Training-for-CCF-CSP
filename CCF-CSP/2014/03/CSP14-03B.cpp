// 2014年03月 第B题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

int n, m;
int order[11];
int w_x[11], w_y[11];
int w_X[11], w_Y[11];
int c_x[11], c_y[11];

inline bool is_in(int cx, int cy, int x1, int y1, int x2, int y2)
{
    if (cx >= x1 &&
        cx <= x2 &&
        cy >= y1 &&
        cy <= y2)
        return true;
    else
        return false;
}
/*
inline void swap(int a, int b)
{
    int c = a;
    a = b;
    b = c;
}
*/

/*
! 错误理解题意：应该输入窗口的“原编号”而非“实时顺序号”
! 故此题没必要麻烦的交换窗口坐标，只需要添加个order[]，以存每层对应的窗口编号（初始层数编号）
inline void v_click(int num)
{
    if (num == n)
        return;
    else
    {
        int x = 0, y = 0, X = 0, Y = 0;
        x = w_x[num];
        X = w_X[num];
        y = w_y[num];
        Y = w_Y[num];

        for (int i = num; i <= n - 1; i++)
        {
            w_x[i] = w_x[i + 1];
            w_y[i] = w_y[i + 1];
            w_X[i] = w_X[i + 1];
            w_Y[i] = w_Y[i + 1];
        }
        w_x[n] = x;
        w_y[n] = y;
        w_X[n] = X;
        w_Y[n] = Y;
    }
}
*/

inline void v_click(int pos)
{
    if (pos == n)
        return;
    else
    {
        int tmp = order[pos];
        for (int i = pos; i <= n - 1; i++)
        {
            order[i] = order[i + 1];
        }
        order[n] = tmp;
    }
}

int main()
{
    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> w_x[i];
        cin >> w_y[i];
        cin >> w_X[i];
        cin >> w_Y[i];
        order[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> c_x[i];
        cin >> c_y[i];
    }

    for (int i = 1; i <= m; i++)
    {
        bool v = 0;
        for (int j = n; j >= 1; j--)
        {
            if (is_in(c_x[i], c_y[i],
                      w_x[order[j]], w_y[order[j]], w_X[order[j]], w_Y[order[j]]))
            {
                cout << order[j] << '\n';
                v_click(j);
                v = 1;
                break;
            }
        }
        if (!v)
            cout << "IGNORED\n";
    }
}