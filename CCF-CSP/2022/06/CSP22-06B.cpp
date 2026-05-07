// 2022-6-B 寻宝！大冒险！
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, L, S;
    cin >> n >> L >> S;

    vector<pair<int, int>> A, B;
    //         < y ,  x >
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        A.push_back(make_pair(y, x));
    }
    for (int i = S; i >= 0; i--)
    {
        for (int j = 0; j <= S; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
                B.push_back(make_pair(i, j));
        }
    }
    //! 排序是错误的
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i].first + S > L || A[i].second + S > L)
            continue;
            
        int dy = A[i].first - B[0].first;
        int dx = A[i].second - B[0].second;

        bool fail = false;
        int bingo = 0;
        for (int j = 0; j < B.size(); j++)
        {
            if (A[i + j].first == B[j].first + dy &&
                A[i + j].second == B[j].second + dx)
            {
                bingo++;
                continue;
            }
            else
            {
                fail = true;
                break;
            }
        }
        if (fail == false && bingo == B.size())
        {
            // 检查有没有多余的树还在藏宝图范围内
            if (i + B.size() < A.size() &&
                A[i + B.size()].first <= A[i].first + S &&
                A[i + B.size()].second <= A[i].second + S)
            {
                fail = true;
            }
            if (fail == false)
                cnt++;
        }
    }
    cout << cnt;
}