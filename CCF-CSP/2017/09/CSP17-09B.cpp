#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 1;
int N, K;
int hook[MAX];

struct Event
{
    int time = 0;
    int type = -1; // 0还 1取
    int key = 0;
};

Event evnt[MAX * 2];

int main()
{
    cin >> N >> K;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        hook[i] = i;
    for (int i = 0; i < K; i++)
    {
        int w, s, c;
        cin >> w >> s >> c;
        evnt[cnt++] = {s, 1, w};
        evnt[cnt++] = {s + c, 0, w};
    }

    sort(evnt, evnt + cnt, [](const Event &a, const Event &b)
         {
        if(a.time!=b.time)
            return a.time<b.time;
        if(a.type!=b.type)
            return a.type<b.type;
        return a.key<b.key; });

    for (int i = 0; i < cnt; i++)
    {
        if (evnt[i].type == 0)
        {
            for (int j = 1; j <= N; j++)
                if (hook[j] == 0)
                {
                    hook[j] = evnt[i].key;
                    break;
                }
        }
        else if (evnt[i].type == 1)
        {
            for (int j = 1; j <= N; j++)
                if (hook[j] == evnt[i].key)
                {
                    hook[j] = 0;
                    break;
                }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (i > 1)
            cout << " ";
        cout << hook[i];
    }
    cout << endl;

    return 0;
}