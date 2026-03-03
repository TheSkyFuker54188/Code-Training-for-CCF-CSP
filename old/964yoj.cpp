#include <iostream>
#include <stack>
#include <vector>

bool isStackShufflePossible(const std::vector<int> &P, const std::vector<int> &Q, int n)
{
    std::stack<int> S;
    int pIndex = 0, qIndex = 0;

    while (pIndex < n)
    {
        // 将 P 的顶元素压入栈 S
        S.push(P[pIndex++]);

        // 尝试将栈 S 的顶元素弹出到 Q
        while (!S.empty() && S.top() == Q[qIndex])
        {
            S.pop();
            qIndex++;
        }
    }

    // 检查是否所有元素都匹配
    return qIndex == n;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> P(n);
    std::vector<int> Q(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> P[i];
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> Q[i];
    }

    if (isStackShufflePossible(P, Q, n))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}
