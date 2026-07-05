#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    int x;
    while (cin >> x)
        a.push_back(x);

    int ans = 0;

    for (int i = 0; i < a.size(); i++)
    {
        ans ^= a[i];
    }
    cout << ans;
}