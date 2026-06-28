//? 原地哈希
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < n; i++)
    {
        int tem = nums[i];
        while (1 <= nums[i] && nums[i] <= n &&
               nums[tem - 1] != tem)
        {
            nums[i] = nums[tem - 1];
            nums[tem - 1] = tem;
        }
    }
    for (int i = 0; i < n; i++)
        if (nums[i] != i + 1)
        {
            cout << i + 1;
            return 0;
        }
}