#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> a(n);
    unordered_map<int, int> b;
    //            数值, idx
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        b[x] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int t = target - a[i];
        if (b.count(t))
        {
            cout << i << " " << b[t];
            return 0;
        }
    }
}