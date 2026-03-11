#include <iostream>

using namespace std;

const int MAX = 1000;
int a[MAX];
int n;

bool pre = false;
bool pos = false;

int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] < a[i])
            pre = true;
        else
            pre = false;

        if (a[i] < a[i + 1])
            pos = true;
        else
            pos = false;

        if (pre != pos)
            ans++;
    }
    cout << ans;
}