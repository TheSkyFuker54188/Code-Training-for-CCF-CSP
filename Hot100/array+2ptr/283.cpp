#include <iostream>
using namespace std;
/* 
fast：遍历整个数组
slow：指向“下一个应该放非零元素的位置 
*/
int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int pf = 0;
    int ps = 0;
    while (pf < n)
    {
        while (pf < n)
        {
            if (nums[pf] != 0)
            {
                int tem = nums[ps];
                nums[ps] = nums[pf];
                nums[pf] = tem;
                ps++;
            }
            pf++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}