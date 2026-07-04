#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;  // 输入数组（排序后）
vector<int> curr;  // 当前正在生成的排列
vector<bool> used; // 标记数字是否已在当前排列中使用
int n;             // 数组长度

void dfs(int idx)
{
    if (idx == n)
    { // 已经填满 n 个位置，输出排列
        for (int i = 0; i < n; ++i)
        {
            if (i)
                cout << " ";
            cout << curr[i];
        }
        cout << "\n";
        return;
    }
    // 按字典序尝试每一个还未使用的数字
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            curr.push_back(nums[i]);
            dfs(idx + 1);
            curr.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    int x;
    // 读取所有输入的整数
    while (cin >> x)
    {
        nums.push_back(x);
    }
    n = nums.size();

    // 排序以保证字典序输出
    sort(nums.begin(), nums.end());

    used.assign(n, false);
    dfs(0);

    return 0;
}