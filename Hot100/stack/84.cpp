#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 如果你从左到右遍历并维护一个递增序列，
那么当你遇到一个比栈顶小的值时，栈顶的“右边界”就到了；
而栈顶的“左边界”正是栈中紧挨着它下面的那个元素
（因为栈递增，下面的一定比它小且最近）
*/
int main()
{
    // 读取所有柱子高度，直到 EOF
    vector<int> heights;
    int h;
    while (cin >> h)
    {
        heights.push_back(h);
    }

    // 在首尾添加哨兵 0，简化边界处理
    heights.insert(heights.begin(), 0);
    heights.push_back(0);

    int ans = 0;
    vector<int> st; // 单调递增栈，存放下标
                    // 栈的严格递增性记录了左边界，从左到右的遍历顺序可以遍历到右边界
    for (int i = 0; i < heights.size(); ++i)
    {
        // 当前高度小于栈顶高度时，说明栈顶柱子的右边界找到了
        while (!st.empty() && heights[st.back()] > heights[i])
        {
            int cur = st.back();
            st.pop_back();
            int left = st.back() + 1; // 弹出 cur 后，新的栈顶 st.back() 存放的是 cur 左边且比它矮的最近柱子的下标
            // 左边界：栈中前一个元素的下标 + 1
            int right = i - 1; // i 是 cur 右边第一个比它矮的柱子
            // 右边界：当前下标 - 1
            int width = right - left + 1;
            ans = max(ans, width * heights[cur]);
        }
        st.push_back(i);
    }

    cout << ans << endl;
    return 0;
}