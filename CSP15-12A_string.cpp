#include <iostream>
#include <string>

using namespace std;

string n;

int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n.size(); i++) //! n.size()前的(int)非必要
    {
        ans += n[i] - '0'; //! n[i]前的(int)非必要
    }
    cout << ans;
}