#include <iostream>

using namespace std;

int n;
int ans;

int main()
{
    cin >> n;

    int b5 = n / 50;
    int b3 = (n - b5 * 50) / 30;
    int b1 = (n - b5 * 50 - b3 * 30) / 10;

    ans = b5 * 7 + b3 * 4 + b1 * 1;
    cout << ans;
}