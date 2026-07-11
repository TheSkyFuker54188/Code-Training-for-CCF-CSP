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

    int k;
    cin >> k;

    for (int i = n-k; i < n; i++)
        cout << a[i] << " ";

    for (int i = 0; i < n-k; i++)
        cout << a[i] << " ";
}