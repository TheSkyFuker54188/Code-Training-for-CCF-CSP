// 2023-05-A 重复局面
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> a;
    int cnt[n];
    for (int i = 0; i < n; i++)
    {
        cnt[i] = 1;
        string b = "";
        for (int j = 0; j < 8; j++)
        {
            string tmp;
            cin >> tmp;
            b += tmp;
        }
        a.push_back(b);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                cnt[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << cnt[i] << "\n";
    }
}