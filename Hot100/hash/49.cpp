#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    // cin.ignore();
    string s[n];

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    unordered_map<string, vector<string>> v;
    // key 为排序后的字符串，value 为字母异位词(vector[])
    for (int i = 0; i < n; i++)
    { // 将字符串排序后作为分组依据
        string key = s[i];
        sort(key.begin(), key.end());
        v[key].push_back(s[i]);
    }

    for (auto &item : v)
    {
        for (int i = 0; i < item.second.size(); i++)
        {
            cout << item.second[i] << " ";
        }
        cout << '\n';
    }
}