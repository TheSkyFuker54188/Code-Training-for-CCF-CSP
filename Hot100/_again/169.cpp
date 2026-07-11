#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    vector<int> a;
    int x;
    while (cin >> x)
    {
        a.push_back(x);
    }

    int cnt = 0;
    int pre = a[0];

    for (int i : a)
    {
        if (cnt == 0)
            pre = i;
        if (pre == i)
            cnt++;
        else
            cnt--;       
    }
    cout << pre;
}