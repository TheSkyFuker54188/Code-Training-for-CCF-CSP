#include <iostream>
#include <stack>

using namespace std;

stack<int> number;

int main()
{
    int n;
    cin >> n;
    int a[n], b, count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        number.push(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        b = number.top();
        number.pop();
        for (int j = i + 1; j < n; j++)
        {
            if (b > a[j])
            {
                count++;
            }
            else
                break;
        }
    }
    cout << count;
    return 0;
}