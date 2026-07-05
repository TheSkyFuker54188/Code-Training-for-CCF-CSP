#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int s = 0;
    int f = 0;

    while (f < n)
    {
        if (a[f] == 0)
        {
            swap(a[f], a[s]);
            s++;
        }
        f++;
    }

    s = n - 1;
    f = n - 1;
    while (f >= 0)
    {
        if (a[f] == 2)
        {
            swap(a[f], a[s]);
            s--;
        }
        f--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}