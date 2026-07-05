//? 单调栈
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> temperatures(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> temperatures[i];
    }

    vector<int> answer(n, 0);
    stack<int> st; // 存下标，保持栈内温度单调递减
                   /*     栈里存的是什么？
                   存的是还没有找到下一个更高温度的日子（的下标）。
                   它们像在排队，等着未来某一天的温度超过自己。 */

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        { // 只要栈不为空，并且今天的温度高于栈顶那天（最近一个低温日）的温度，
            // 就说明栈顶那天终于等到了第一个更高的温度。
            int prev = st.top();
            st.pop();                // 栈顶那天已经找到了答案，就该从“等待队列”里退出了。
            answer[prev] = i - prev; // 栈顶那天与今天的天数差就是答案
        }
        st.push(i); // 今天的天数也入栈，等待未来某一天温度超过它
    }

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
            cout << " ";
        cout << answer[i];
    }
    cout << endl;

    return 0;
}