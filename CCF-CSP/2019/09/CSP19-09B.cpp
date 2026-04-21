// 2019-9-B 小明种苹果（续）
#include <iostream>

using namespace std;

int n;

int main()
{
    //freopen("in.txt", "r", stdin);
    int a[1000] = {0};

    int t = 0;
    int d = 0;
    int drop[1000] = {0};
    int e = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            if (num > 0)
            {
                if (a[i] == 0)
                    a[i] = num;
                else if (a[i] == num)
                    ;
                else if (a[i] != num)
                {
                    drop[i] = 1;
                    a[i] = num;
                }
            }
            else
            {
                a[i] += num;
            }
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        t += a[i];
        d += drop[i];
        e += (drop[i] == 1) && (drop[i + 1] == 1) && (drop[i + 2] == 1);
    }
    t += a[n - 2] + a[n - 1];
    d += drop[n - 2] + drop[n - 1];
    e += ((drop[n - 2] == 1) && (drop[n - 1] == 1) && (drop[0] == 1)) //
         + ((drop[n - 1] == 1) && (drop[0] == 1) && (drop[1] == 1));

    //cout << "No.0=" << a[0] << " No.1=" << a[1] << " No.2=" << a[2] << " No.3=" << a[3] << endl;
    cout << t << " " << d << " " << e;
}

// freopen("in.txt", "r", stdin);