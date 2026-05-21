// 2024-09-A 密码
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int mark = 2;

        int a[26] = {0};
        int A[26] = {0};
        int num[26] = {0};
        int c[26] = {0};

        bool ia = false;
        bool in = false;
        bool ic = false;

        string psw;
        cin >> psw;
        for (int p = 0; p < psw.length(); p++)
        {
            if (psw[p] >= 'a' && psw[p] <= 'z')
            {
                a[psw[p] - 'a']++;
                ia = true;
            }
            else if (psw[p] >= 'A' && psw[p] <= 'Z')
            {
                A[psw[p] - 'A']++;
                ia = true;
            }
            else if (psw[p] >= '0' && psw[p] <= '9')
            {
                num[psw[p] - '0']++;
                in = true;
            }
            else if (psw[p] == '*')
            {
                c[0]++;
                ic = true;
            }
            else if (psw[p] == '#')
            {
                c[1]++;
                ic = true;
            }
        }

        for (int j = 0; j < 26; j++)
        {
            if (a[j] > 2 || A[j] > 2 || num[j] > 2 || c[j] > 2)
            {
                mark = 1;
                break;
            }
        }
        if (ia == false || in == false || ic == false)
            mark = 0;

        cout << mark << "\n";
    }
}