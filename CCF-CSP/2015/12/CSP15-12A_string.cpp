// 2015年12月 第A题
// 涉及考点：字符串处理（按文件名推定）

#include <iostream>
#include <string>

using namespace std;

string n;

int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n.size(); i++) //! n.size()前的(int)非必要
    {
        ans += n[i] - '0'; //! n[i]前的(int)非必要
    }
    cout << ans;
}