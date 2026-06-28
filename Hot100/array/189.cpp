#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        nums.push_back(tem);
    }
    int k;
    cin >> k;

    vector<int> ans(n);
    for (int i = 0; i < k; i++)
    {
        ans[i] = nums[n - k + i];
    }
    for (int i = k; i < n; i++)
    {
        ans[i] = nums[i - k];
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}