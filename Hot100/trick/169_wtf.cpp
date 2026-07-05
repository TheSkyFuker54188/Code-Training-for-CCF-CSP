//? 摩尔投票
// 若记 众数 的票数为 +1 ，非众数 的票数为 −1 ，则一定有所有数字的 票数和 >0
// 若数组的前 a 个数字的 票数和 =0 ，则 数组剩余 (n−a) 个数字的 票数和一定仍 >0 ，即后 (n−a) 个数字的 众数仍为 x
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int x;
    vector<int> a;
    while (cin >> x)
        a.push_back(x);

    n = a.size();

    int vote = 0;
    int q;
    for (int i = 0; i < n; i++)
    {
        if (vote == 0)
            q = a[i];
        if (a[i] != q)
            vote--;
        else
            vote++;
    }
    cout << q;
}