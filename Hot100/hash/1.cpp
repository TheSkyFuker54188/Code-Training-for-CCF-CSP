#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    int nums[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    unordered_map<int, int> num2idx;
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        int complement = target - num;
        if (num2idx.count(complement))
            cout << i << " " << num2idx[complement] << '\n';
        num2idx[num] = i;
    }
}