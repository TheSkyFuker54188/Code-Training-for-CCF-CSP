#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            k++;
        else
            a[i - k] = a[i];
    }
    for (int i = n - k; i < n; i++)
        a[i] = 0;

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}