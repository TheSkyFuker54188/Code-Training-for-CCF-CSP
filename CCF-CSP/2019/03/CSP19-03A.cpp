// 2019-3-A 小中大
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e5;
int a[MAX];

int main()
{
    // freopen("in.txt","r",stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int max = a[n - 1];
    int min = a[0];

    cout << max << " ";
    if (n % 2 == 0)
    {
        long long sum = (long long)a[n / 2 - 1] + a[n / 2];
        if (sum % 2 != 0)
        { //! 当 double 类型的数值过大时，cout 会默认使用科学计数法进行输出
            printf("%.1f ", sum / 2.0);
        }
        else
        {
            cout << sum / 2 << " ";
        }
    }
    else
    {
        cout << a[n / 2] << " ";
    }
    cout << min;
}