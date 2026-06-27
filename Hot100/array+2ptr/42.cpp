#include <iostream>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int l_max = h[0];
    int r_max = h[n - 1];

    int l = 0;
    int r = n - 1;

    int v = 0;

    while (l < r)
    {
        l_max = max(l_max, h[l]);
        r_max = max(r_max, h[r]);
        if (h[l] < h[r])
        {
            v += l_max - h[l];
            l++;
        }
        else
        {
            v += r_max - h[r];
            r--;
        }
    }
    cout << v;
}