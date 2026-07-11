#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    // vector<int> a(n);
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int i = 0;
    int j = 0;
    int k = n - 1;

    while (j <= k)
    {
        if (a[j] == 0)
        {
            swap(a[i], a[j]);
            i++;
            j++;
        }
        else if (a[j] == 2)
        {
            swap(a[k], a[j]);
            k--; //! 不确定新来的还要不要继续换，所以不动 j
        }
        else
            j++;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}