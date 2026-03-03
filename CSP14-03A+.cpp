#include <iostream>

using namespace std;

inline bool opposite(int a, int b)
{
    if (a + b == 0)
        return true;
    else
        return false;
}

int n;
int num[500];
int ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if(num[i] == 0) continue;
        for (int j = i + 1; j < n; j++)
        {
            if (opposite(num[i], num[j]))
            {
                ans++;
                num[j] = 0;
                break;
            }
        }
    }
    cout << ans;
}