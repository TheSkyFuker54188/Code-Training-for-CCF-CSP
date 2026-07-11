#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, bool> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (b.find(a[i]) == b.end())
            b[a[i]] = true;
        else
        {
            cout << "true";
            return 0;
        }
    }
    cout << "false";
            return 0;
}