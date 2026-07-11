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

    //? 每一轮把当前未排序部分的最小（或最大）值“冒泡”到正确的位置
    for (int i = 0; i < n - 1; i++) // todo   i 是“本轮要被填满的位置”
    {                               // todo i 指向本轮“最小元素”应该去的位置
        bool swapped = false;
        for (int j = n - 1; j > i; j--) // todo  j 从末尾往回走
        {
            if (a[j - 1] > a[j]) // todo j 从数组最右边开始，向左一直走到 j = i+1
            {
                swap(a[j - 1], a[j]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    for (auto i : a)
        cout << i << " ";
}