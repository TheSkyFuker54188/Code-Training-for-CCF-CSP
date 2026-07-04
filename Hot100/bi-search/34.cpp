// 等号布置产生巧妙的影响
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

    int target;
    cin >> target;

    int first = -1;
    int second = -1;

    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (target >= a[mid])
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if (a[l-1] == target)
        second = l-1;
/*         
因为条件 target >= a[mid] 包含等号，l 会一直右移，直到指向第一个 大于 target 的位置。
所以真正最后一个等于 target 的位置是 l - 1，不是 l 
*/

    l = 0;
    r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (target > a[mid])
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if (a[l] == target)
        first = l;

    cout << first << " " << second;
}