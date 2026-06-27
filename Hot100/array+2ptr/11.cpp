#include <iostream>
#include <cmath>
using namespace std;
/* "有目标地去移动下标"
从两侧开始试
最左和最右的组合，此时"宽度"已经是最大的了。
接下来想再得到更大的容量，只能依赖于 "高度" 变高 

增大短板
高度较小的指针内收
*/
int main()
{
    int n;
    cin >> n;
    int l = 0;
    int r = n - 1;
    int h[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int max = 0;
    while (l != r)
    {
        int H = min(h[l], h[r]);
        int v = H * (r - l);
        if (v > max)
            max = v;
        if (H == h[l])
            l++;
        else
            r--;
    }
    cout << max;
}