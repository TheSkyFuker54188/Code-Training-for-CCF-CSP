// 2020-12-A 期末预测之安全指数
#include <iostream>
/* #include <algorithm> */

using namespace std;

int main()
{
    int score = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w, s;
        cin >> w >> s;
        score += w * s;
    }
    int y = max(score, 0);
    cout<<y;
}