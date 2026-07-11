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

    int right = 0;
    for (int i = 0; i < n; i++)
    {
        if (i <= right)
        {
            right = max(right, a[i] + i);
        }
    }
    if (right >= n)
    {
        cout << "true";
        return 0;
    }
    cout << "false";
    return 0;
}