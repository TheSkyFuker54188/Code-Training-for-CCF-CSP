#include <iostream>

using namespace std;

const int MAX = 1000;
int n;
int a[MAX];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int big = 0;
        int small = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] < a[j])
                big++;
            else if (a[i] > a[j])
                small++;
        }
        if (big == small)
        {
            cout << a[i];
            return 0;
        }
    }
    cout << -1;
}