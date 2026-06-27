#include <iostream>
#include <algorithm> //sort
// #include <cstdlib>   //qsort

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums, nums + n);

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int target = -nums[i];
        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum == target)
            {
                cout << nums[i] << " " << nums[l] << " " << nums[r] << '\n';
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1])
                    l++;
                while (l < r && nums[r] == nums[r + 1])
                    r--;
                // break;
            }
            else if (sum < target)
            {
                l++;
            }
            else if (sum > target)
            {
                r--;
            }
        }
    }
}