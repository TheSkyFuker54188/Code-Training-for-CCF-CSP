//! f(i)代表以i为右端点时，它能够得到的最大子数组和
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = a[0];

    int last = a[0];
    int thes = a[0];

    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        if (last > 0) // todo 判断依据是前驱符不符合条件，而非新增变量符不符合条件。因此不要把这道题误解成贪心问题
        {
            thes = last + x;
        }
        else
        {
            thes = x; //! 另起一段
        }
        ans = max(ans, thes);
        last = thes; //! 滚动变量法别忘了更新前驱
    }
    cout << ans;
}