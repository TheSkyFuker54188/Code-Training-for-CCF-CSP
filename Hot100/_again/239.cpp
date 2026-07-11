#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    deque<int> q;

    for (int i = 0; i < n; i++) //! 循环变量 i 并不是窗口的左边界，而是右边界
    {
        int num = a[i];
        if (!q.empty() && q.front() < i-k+1)
        {
            q.pop_front();
            /* for (auto it = q.begin(); it != q.end(); ++it)
                cout << *it << " ";
            cout << '\n'; */
        }
        while (!q.empty() && num > a[q.back()])
        {
            q.pop_back();
            /* for (auto it = q.begin(); it != q.end(); ++it)
                cout << *it << " ";
            cout << '\n'; */
        }

        q.push_back(i);
        /* for (auto it = q.begin(); it != q.end(); ++it)
            cout << *it << " ";
        cout << '\n'; */
        if (i >= k - 1)
            cout << a[q.front()] << " ";
    }
}