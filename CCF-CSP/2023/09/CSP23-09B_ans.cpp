// 2023-09-B 坐标变换（其二）
//? 前缀和思想
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int MAXN = 100005;

// pre_logk[i] : 前 i 个操作中拉伸系数 k 的自然对数之和
// pre_theta[i]: 前 i 个操作中旋转角度 theta 的累加和
double pre_logk[MAXN];
double pre_theta[MAXN];

int main()
{
    // 加速 IO，应对大规模数据
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 前缀和的第一个元素设为 0，方便处理 i=1 的情况
    pre_logk[0] = 0.0;
    pre_theta[0] = 0.0;

    // 读入 n 个操作，构建前缀和
    for (int i = 1; i <= n; ++i)
    {
        int type;
        double val;
        cin >> type >> val;

        // 先继承前一个状态
        pre_logk[i] = pre_logk[i - 1];
        pre_theta[i] = pre_theta[i - 1];

        if (type == 1)
        {                            // 拉伸操作
            pre_logk[i] += log(val); // 对数相加
        }
        else
        {                        // 旋转操作
            pre_theta[i] += val; // 角度直接相加
        }
    }

    // 设置输出格式：定点小数，保留足够精度（10位小数）
    cout << fixed << setprecision(10);

    // 处理 m 个查询
    for (int q = 0; q < m; ++q)
    {
        int i, j;
        long long x, y; // 输入坐标是整数
        cin >> i >> j >> x >> y;

        // 1. 计算区间的拉伸倍数 K
        double logK = pre_logk[j] - pre_logk[i - 1];
        double K = exp(logK); // 恢复成真实的乘积

        // 2. 计算区间的旋转总角度 theta
        double theta = pre_theta[j] - pre_theta[i - 1];

        // 3. 一次计算最终坐标
        double cos_t = cos(theta);
        double sin_t = sin(theta);
        double new_x = K * (x * cos_t - y * sin_t);
        double new_y = K * (x * sin_t + y * cos_t);

        cout << new_x << " " << new_y << "\n";
    }

    return 0;
}