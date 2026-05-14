// 2022-3-B 出行计划
//? 差分 + 前缀和
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 400000 + 5; // q+k 最大可能到 300000，多开一些

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> diff(MAXN, 0); // 差分数组

    for (int i = 0; i < n; i++)
    {
        int t, c;
        cin >> t >> c;

        // 能进入该场所的 q 满足：t - c + 1 <= q + k <= t
        // 即 q + k 落在区间 [t - c + 1, t] 内
        int L = t - c + 1;
        if (L < 0)
            L = 0;
        int R = t;

        diff[L] += 1;
        diff[R + 1] -= 1;
        //* 从左到右累加这些操作，每到一点，当前累积的值就是该点被覆盖的次数
    }
    //? 

    // 前缀和还原，diff[x] 表示“在时刻 x 进入场所”能满足的计划数
    for (int i = 1; i < MAXN; i++)
    {
        diff[i] += diff[i - 1];
    }

    // 处理查询
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        int idx = q + k;
        if (idx < MAXN)
            cout << diff[idx] << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}