#include <iostream>
#include <string>
#include <unordered_map>

//? 经典的“右扩左缩”滑动窗口模板

using namespace std;

int main()
{
    string s;
    getline(cin,s);

    unordered_map<char, int> m;
    //             c , last_idx
    int L = 0;

    int l = 0;
    for (int r = 0; r < s.length(); r++)
    {
        char c = s[r];
        if (m.find(c) != m.end()) // 找到重复字母
        {
            l = max(l, m[c] + 1);
        }
        m[c] = r;

        L = max(L, r - l + 1);
    }
    cout << L;
}