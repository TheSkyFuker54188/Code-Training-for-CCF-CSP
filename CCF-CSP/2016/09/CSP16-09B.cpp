// 2016年09月 第B题
// 涉及考点：算法 + 数据结构）

#include <iostream>

using namespace std;

const int MAX = 100;

bool seat[20][5];
int p[MAX];
int room[20];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < 20; i++)
    {
        room[i] = 5;
        for (int j = 0; j < 5; j++)
        {
            seat[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        int s = p[i];

        for (int j = 0; j < 20; j++)
        {
            if (s <= room[j])
            {
                room[j] -= s;
                for (int k = 0; k < 5; k++)
                {
                    if (s > 0)
                    {
                        if (seat[j][k] == false)
                        {
                            seat[j][k] = true;
                            cout << 5 * j + k + 1 << " ";
                            s--;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                cout << endl;
                break;
            }
        }
        while (s > 0)
        {
            bool done = false;
            for (int j = 0; j < 20; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (s > 0)
                    {
                        if (seat[j][k] == false)
                        {
                            seat[j][k] = true;
                            cout << 5 * j + k + 1 << " ";
                            s--;
                            room[j]--;
                        }
                    }
                    else
                    {
                        cout << endl;
                        done = true;
                        break;
                    }
                }
                if (done == true)
                    break;
            }
        }
    }
}
