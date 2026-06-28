#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    unordered_map<char, int> m;
    for (char c : t)
        m[c]++;

    unordered_map<char, int> w;

    int l = 0;
    int r = 0;
    int v_cat = 0;

    int ansl = -1;
    int ansr = -1;

    for (r = 0; r < s.length(); r++)
    {
        char c = s[r];

        if (m.count(c))
        {
            w[c]++;
            if (w[c] == m[c]) // 严格等于 => 只记录一次，防止同字符重复算数
                v_cat++;
        }

        while (v_cat == m.size())
        { // 已达成，求最短
            if (ansl == -1 ||
                (r - l + 1) < (ansr - ansl + 1))
            {
                ansl = l;
                ansr = r;
            }

            char out = s[l];
            if (m.count(out))
            {
                if (w[out] == m[out])
                    v_cat--;
                w[out]--;
            }
            l++;
        }
    }

    if (ansl == -1)
    {
        cout << "";
        return 0;
    }
    else
    {
        cout << s.substr(ansl, ansr - ansl + 1);
    }
}