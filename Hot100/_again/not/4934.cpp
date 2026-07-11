#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> a;
vector<int> even;
vector<int> odd;

void quick(vector<int> &b, int l, int r)
{
    if (l >= r)//! 别忘了！！
        return;
    int l0 = l;
    int r0 = r;
    int piv = b[l];

    while (l < r)
    {
        while (l < r && b[r] >= piv)
            r--;
        b[l] = b[r];
        while (l < r && b[l] <= piv)
            l++;
        b[r] = b[l];
    }
    b[l] = piv;
    quick(b, l0, l - 1);
    quick(b, l + 1, r0);
}

int main()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
    }
    if (!even.empty())
        quick(even, 0, even.size() - 1);
    if (!odd.empty())
        quick(odd, 0, odd.size() - 1);

    for (auto i : odd)
        cout << i << " ";
    for (auto i : even)
        cout << i << " ";
}