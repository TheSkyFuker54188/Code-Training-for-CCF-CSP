#include <iostream>
#include <vector>

using namespace std;
//? 在前缀和数组suf中，选出两个数使得它们的差是k

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n + 1);
    vector<int> suf(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    suf[0] = 0;
    for (int i = 1; i <= n; i++)
        suf[i] = suf[i - 1] + nums[i];

    int cnt = 0;

    for (int r = n; r > 0; r--)
    {
        int target = suf[r] - k;
        int l = r;
        while (l >= 0)//! 双层循环
        {
            if (suf[l] == target)
                cnt++;
        }
    }
    cout << cnt;
}