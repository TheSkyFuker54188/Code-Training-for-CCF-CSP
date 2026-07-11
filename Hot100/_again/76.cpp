#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    unordered_map<char, int> a;
    unordered_map<char, int> b;

    for (char c : t)
        a[c]++;

    int n = s.size();

    int l = 0;
    int r = 0;

    int ansl = -1;
    int ansr = n;

    int target = a.size();
    int match = 0;

    for (r = 0; r < n; r++)
    {
        char in = s[r];
        if (a.find(in) != a.end())
        {
            b[in]++;
            if (b[in] == a[in])
                match++;
        }

        while (match == target)
        {
            if (ansl == -1 ||
                (r - l) < (ansr - ansl))
            {
                ansl = l;
                ansr = r;
            }

            char out = s[l];
            if (a.find(out) != a.end())
            {
                if (b[out] == a[out])
                    match--;
                b[out]--;
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