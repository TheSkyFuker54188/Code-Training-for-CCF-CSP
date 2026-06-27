#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s, p;
    getline(cin, s);
    getline(cin, p);

    vector<int> v_s(26, 0);
    vector<int> v_p(26, 0);

    for (char c : p)
        v_p[c - 'a']++;

    for (int i = 0; i < p.length(); i++)
        v_s[s[i] - 'a']++;

    if (v_s == v_p)
        cout << 0 << " ";

    for (int i = p.length(); i < s.length(); i++)
    {
        v_s[s[i] - 'a'] += 1;
        v_s[s[i - p.length()] - 'a'] -= 1;
        if (v_s == v_p)
            cout << i - p.length() + 1 << " ";
    }
}