#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> a[i];

    int fast = a[0];
    int slow = a[0];
    do
    {
        fast = a[a[fast]];
        slow = a[slow];
    } while (fast != slow);

    fast = a[0];

    while (fast != slow)
    {
        slow = a[slow];
        fast = a[fast];
    }
    cout << fast;
}