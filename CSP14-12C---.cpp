#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int MAX = 5000 + 1;

stringstream line[MAX];

struct Stock
{
    string act = {};
    float p = 0;
    int s = 0;
};

int p0;
int sum;

int main()
{
    Stock stock[MAX];

    int read = 0;

    while (1)
    {
        string line_tmp;
        if (getline(cin, line_tmp))
        {
            line[read] << line_tmp;
            read++;
        }
        else
            break;
    }

    for (int i = 0; i < read; i++)
    {
        string line_act;
        float line_p;
        int line_s;
        line[i] >> line_act;

        if (line_act == "cancel")
        {
            int line_idx;
            line[i] >> line_idx;
            stock[line_idx].act = "cancel";
        }
        else
        {
            line[i] >> line_p;
            line[i] >> line_s;
            if (line_act == "buy")
            {
                stock[i].act = "buy";
                stock[i].p = line_p;
                stock[i].s = line_s;
            }
            else if (line_act == "sell")
            {
                stock[i].act = "sell";
                stock[i].p = line_p;
                stock[i].s = line_s;
            }
        }
    }

    for (int i = 0; i < read; i++)
    {
        if (stock[i].act != "cancel")
        {
            int s_buy = 0;
            int s_sell = 0;

            for (int j = 0; j < read; j++)
            {
                if (stock[i].act == "buy" && stock[j].p >= stock[i].p)
                {
                    s_buy += stock[j].s;
                }
                else if (stock[i].act == "sell" && stock[j].p <= stock[i].p)
                {
                    s_sell += stock[j].s;
                }
            }
            int s_tmp = min(s_buy, s_sell);
            if (s_tmp > sum)
            {
                sum = s_tmp;
                if (stock[i].p > p0)
                {
                    p0 = stock[i].p;
                }
            }
        }
        else
            break;
    }
    printf("%.2f %d\n", p0, sum);
}