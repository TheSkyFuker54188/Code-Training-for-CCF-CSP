#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    string p;
    getline(cin, s);
    getline(cin, p);

    vector<int> v_s(26, 0);
    vector<int> v_p(26, 0);
    int l_s = s.size();
    int l_p = p.size();

    for (char c : p)
        v_p[c - 'a']++;

    for (int i = 0; i <= l_s - l_p; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < l_p; j++)
                v_s[s[j] - 'a']++;
            if (v_s == v_p)
                cout << 0 << " ";
            continue;
        }

        char drop = s[i-1];
        char load = s[i + l_p - 1];
        v_s[drop - 'a']--;
        v_s[load - 'a']++;

        if (v_s == v_p)
            cout << i << " ";
    }
}