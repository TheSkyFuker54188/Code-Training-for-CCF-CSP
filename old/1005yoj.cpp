//!  不是这种实现方法！！！
#include <iostream>

using namespace std;

int pre[10000001];

int find(int x)
{
    while (pre[x] != x)
        x = pre[x];
    return x;
}

int main()
{
    int N, k;
    cin >> N >> k;
    for (int i = 1; i <= 3 * N; i++)
    {
        pre[i] = i;
    }
    int op, a, b;
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> op >> a >> b;
        if (a > N || b > N)
        {
            result++;
            continue;
        }
        if (op == 1)
        {
            if (find(a + N) == find(b) || find(a) == find(b + N))
                result++;
            else
            {
                pre[find(a)] = find(b);
                pre[find(a + N)] = find(b + N);
                pre[find(a + 2 * N)] = find(b + 2 * N);
            }
        }
        else
        {
            if (find(a) == find(b) || find(a) == find(b + N))
                result++;
            else
            {
                pre[find(a + N)] = find(b);
                pre[find(a + 2 * N)] = find(b + N);
                pre[find(a)] = find(b + 2 * N);
            }
        }
    }
    cout << result << endl;
    return 0;
}