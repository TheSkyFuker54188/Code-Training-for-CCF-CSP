#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<char, int> a;

    for (int i = n - 1; i >= 0; i--)
    {
        char c = s[i];
        if (a.find(c) == a.end())
            a[c] = i;
    }

    int l = 0;
    int r = -1;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        r = max(r, a[c]);
        if (i == r)
        {
            cout << r - l + 1 << " ";
            l = r + 1;
        }
    }
}