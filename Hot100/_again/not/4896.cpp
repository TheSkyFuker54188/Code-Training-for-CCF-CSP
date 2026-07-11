#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)//todo 外层循环：i 代表已经排好序的轮数，也等于数组末尾已归位的元素个数
    {
        bool swapped = false;
        for (int j = 0; j < n-1; j++)//todo 优化写法是 j < n-1-i，利用尾部已经有序的特点减少比较次数
        {
            if (a[j] > a[j + 1]) 
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    for (auto i : a)
        cout << i << " ";
}