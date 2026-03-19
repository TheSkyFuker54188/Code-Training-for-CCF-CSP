// 2017年09月 第B题
// 涉及考点：算法 + 数据结构）

#include <iostream>
#include <algorithm>
using namespace std;

// 事件结构体
struct Event
{
    int time; // 事件发生时刻
    int type; // 0 = 还钥匙, 1 = 取钥匙 (0 < 1, 保证还先于取)
    int key;  // 钥匙编号
};

int hook[1001];     // 钥匙盒，hook[i] 表示第 i 个挂钩上的钥匙编号，0 表示空
Event events[2001]; // 最多 K 个老师，每人 2 个事件

int main()
{
    int N, K;
    cin >> N >> K;

    // 初始化：钥匙按编号顺序挂好
    for (int i = 1; i <= N; i++)
        hook[i] = i;

    // 读入每位老师的信息，拆成两个事件
    int cnt = 0;
    for (int i = 0; i < K; i++)
    {
        int w, s, c;
        cin >> w >> s >> c;
        // 取钥匙事件：时刻 s
        events[cnt++] = {s, 1, w};
        // 还钥匙事件：时刻 s + c
        events[cnt++] = {s + c, 0, w};
    }

    // 排序：时间优先 → 还优先于取 → 编号小优先
    sort(events, events + cnt, [](const Event &a, const Event &b)
         { 
        //?  lambda 表达式 作为自定义比较函数
        if (a.time != b.time)
            return a.time < b.time;
        if (a.type != b.type)
            return a.type < b.type; // 0(还) < 1(取)
        return a.key < b.key; });

    // 依次处理每个事件
    for (int i = 0; i < cnt; i++)
    {
        if (events[i].type == 0)
        {
            // 还钥匙：找最左边的空挂钩
            for (int j = 1; j <= N; j++)
            {
                if (hook[j] == 0)
                {
                    hook[j] = events[i].key;
                    break;
                }
            }
        }
        else
        {
            // 取钥匙：找到该钥匙并取走
            for (int j = 1; j <= N; j++)
            {
                if (hook[j] == events[i].key)
                {
                    hook[j] = 0;
                    break;
                }
            }
        }
    }

    // 输出结果
    for (int i = 1; i <= N; i++)
    {
        if (i > 1)
            cout << " ";
        cout << hook[i];
    }
    cout << endl;

    return 0;
}

/*
[捕获列表](参数列表) { 函数体 }

[捕获列表]：排序时需要用到外部变量
[]	不捕获任何外部变量
[=]	捕获所有外部变量（值拷贝）
[&]	捕获所有外部变量（引用）
[x, &y]	x 按值，y 按引用
*/