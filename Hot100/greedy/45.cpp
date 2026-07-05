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

    int this_jmp_lmt = 0;
    int next_jmp_lmt = 0;
    int cnt = 0;

    for (int i = 0; i < n - 1; i++)
    { //!  i 只到 n-2：
        /*
! 某次跳跃后，边界 end 刚好被更新为 n-1（即恰好覆盖终点）。
! 然后循环继续，i 走到了 n-1，此时 i == end，条件成立，会错误地再加一次跳跃。 */

        int w = i + a[i];
        if (w > next_jmp_lmt)
            next_jmp_lmt = w;

        if (i == this_jmp_lmt)
        {
            cnt++;
            this_jmp_lmt = next_jmp_lmt;
        }
    }
    cout << cnt;
}