// 2015年12月 第A题
// 整数/数值处理（按文件名推定）

#include <iostream>

using namespace std;

int main()
{
    int n;
    int ans = 0;

    cin >> n;

    while (n != 0)
    {
        ans += n % 10;
        n /= 10;
    }
    cout << ans;
}