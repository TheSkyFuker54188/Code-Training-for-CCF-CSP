#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    // freopen("in,txt", "r", stdin);
    string s, p;
    getline(cin, s);
    getline(cin, p);

    int len = p.length();
    sort(p.begin(), p.end());

    for (int l = 0; l < s.length(); l++)
    {
        string win = s.substr(l, len);
        sort(win.begin(), win.end());
        if (win == p)
            cout << l << " ";
    }
}