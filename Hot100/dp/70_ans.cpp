#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // f(0) = 1, f(1) = 1
    int dp2 = 1; // f(i-2)
    int dp1 = 1; // f(i-1)

    // 从第2阶开始滚动计算
    for (int i = 2; i <= n; ++i)
    {
        int dp_now = dp1 + dp2; // f(i) = f(i-1) + f(i-2)
        dp2 = dp1;
        dp1 = dp_now;
    }

    // n == 1 时不会进入循环，dp1 直接就是答案
    cout << dp1 << endl;
    return 0;
}