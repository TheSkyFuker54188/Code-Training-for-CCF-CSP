#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x;
    vector<int> a;
    while (cin >> x)
        a.push_back(x);
    int n = a.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans ^= a[i];
    }
    cout << ans;
}