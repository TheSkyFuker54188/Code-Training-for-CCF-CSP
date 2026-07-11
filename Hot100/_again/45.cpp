#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ths = 0;
    int cnt = 0;
    int right = 0;

    for (int i = 0; i < n - 1; i++)
    {
        right = max(right, i + a[i]);
        if (i == ths)
        {
            cnt++;
            ths = right;
        }
    }
    cout << cnt;
}