#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> ans;
    vector<int> last(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (i > last[c - 'a'])
        {
            last[c - 'a'] = i;
        }
    }

    int left = 0;  // 当前正在构建的片段的起始下标（含）
    int right = 0; // 当前片段为了包含其中所有字符，至少必须到达的下标（含）
    for (int i = 0; i < s.size(); i++)
    {
        if (last[s[i] - 'a'] >= right)
            right = last[s[i] - 'a'];
        if (i == right)
        {
            ans.push_back(right - left + 1);
            left = right + 1; // 下一个片段的左边界
        }
    }
    for (int i : ans)
        cout << i << " ";
}