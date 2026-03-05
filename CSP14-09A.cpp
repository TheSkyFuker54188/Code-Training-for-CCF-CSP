#include <iostream>

using namespace std;

int n;
int num[1000];
int cnt;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int j = 0; j < n - 1; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (abs(num[j] - num[k]) == 1)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}