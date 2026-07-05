/* 把数组看成一张有向图，下标 i 指向 nums[i]
共有 n+1 个位置，但值只在 1~n 之间，所以这张图一定有环，而重复数字就是环入口
环入口代表着同时有两个下标指向这里
即：存在nums[i]=nums[j] */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
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