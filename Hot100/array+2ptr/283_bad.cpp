#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    int num[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int ptr1 = 0;
    int cnt0 = 0;

    while (ptr1 < n)
    {
        while (num[ptr1] == 0 && ptr1 < n)
        {
            cnt0++;
            ptr1++;
        }
        num[ptr1 - cnt0] = num[ptr1];
        num[ptr1] = 0;
        ptr1++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << num[i];
        if (i != n - 1)
            cout << " ";
    }
}