// 2019-12-A 报数
#include <iostream>

using namespace std;
int a[4];
// 0  1  2  3
// 丁 甲 乙 丙

int main()
{
    int n;
    int cnt = 0;
    cin >> n;

    int i = 0;
    while (cnt < n)
    {
        i++;
        int num = i % 4;
        int b1, b2, b3;
        b1 = i % 10;
        b2 = (i / 10) % 10;
        b3 = i / 100;

        bool skip = false;
        if (i % 7 == 0)
        {
            a[num]++;
            skip = true;
        }
        else if (b1 == 7 || b2 == 7 || b3 == 7)
        {
            a[num]++;
            skip = true;
        }
        if (skip == false)
            cnt++;
    }
    cout << a[1] << endl
         << a[2] << endl
         << a[3] << endl
         << a[0] << endl;
}