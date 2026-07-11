#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    unordered_map<string, vector<string>> m;

    for (int i = 0; i < n; i++)
    {
        string tem;
        cin >> tem;
        s[i] = tem;
        sort(tem.begin(), tem.end());
        m[tem].push_back(s[i]);
    }

    for (auto i : m)
    {
        for (int j = 0; j < i.second.size(); j++)
            cout << i.second[j] << " ";
        cout << '\n';
    }
}