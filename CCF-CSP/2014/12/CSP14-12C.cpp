// 2014年12月 第C题
// 算法 + 数据结构）

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

const int MAX = 5000 + 1;

stringstream line[MAX];

struct Stock
{
    string act = "";
    double p = 0;
    long long s = 0;
};

double p0;
long long sum;

int main()
{
    Stock stock[MAX];

    int read = 0;

    while (1)
    {
        string line_tmp;
        if (getline(cin, line_tmp))
        {
            if (line_tmp.empty())
                continue;
            line[read] << line_tmp;
            read++;
        }
        else
            break;
    }

    for (int i = 0; i < read; i++)
    {
        string line_act;
        double line_p;
        long long line_s;

        line[i] >> line_act;

        if (line_act == "cancel")
        {
            int line_idx;
            line[i] >> line_idx;
            stock[i].act = "cancel";
            stock[line_idx - 1].act = "canceled";
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
        if (stock[i].act == "buy" || stock[i].act == "sell")
        {
            long long s_buy = 0;
            long long s_sell = 0;

            for (int j = 0; j < read; j++)
            {
                if (stock[j].act == "buy" && stock[j].p >= stock[i].p)
                {
                    s_buy += stock[j].s;
                }
                else if (stock[j].act == "sell" && stock[j].p <= stock[i].p)
                {
                    s_sell += stock[j].s;
                }
            }
            long long s_tmp = min(s_buy, s_sell);
            if (s_tmp > sum ||
                (s_tmp == sum && stock[i].p > p0))
            {
                sum = s_tmp;
                p0 = stock[i].p;
            }
        }
    }
    printf("%.2f %lld\n", p0, sum);
    return 0;
}