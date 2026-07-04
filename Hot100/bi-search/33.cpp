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

    bool t_first = false;
    if (target > a[n - 1])
    {
        t_first = true;
    }

    int l = 0, r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        bool m_first = false;
        if (a[mid] > a[n - 1])
        {
            m_first = true;
        }

        if (t_first && !m_first)
        {
            r = mid - 1;
        }
        else if (!t_first && m_first)
        {
            l = mid + 1;
        }
        else if (t_first == m_first)
        {
            if (target == a[mid])
            {
                cout << mid;
                return 0;
            }
            else if (target > a[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    cout << -1;
    return 0;
}