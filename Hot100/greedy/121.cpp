// 从左往右枚举每一天
// 过程中维护过去这些天里最低的买入价格
// 两者相减就是第i天的最优解
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int ans = 0;
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (m.empty() || p[i] <= m.back())
        {
            m.push_back(p[i]);
        }
        else
            m.push_back(m.back());

        if(p[i]-m[i]>ans)
        ans=p[i]-m[i];
    }

    cout<<ans;
}