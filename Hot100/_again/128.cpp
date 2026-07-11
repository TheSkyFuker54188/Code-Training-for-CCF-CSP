#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_set<int> b(n); //? 借助set，不必排序也能从大到小顺着查

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b.insert(a[i]);
    }

    int ans = 1;
    for (auto i : b)
    {
        int l = 1;
        int cur = i;
        while (b.find(cur + 1) != b.end()) //? 每个作为起点往后找
        {
            l++;
            cur++;
        }
        ans = max(ans, l);
    }
    cout << ans;
}