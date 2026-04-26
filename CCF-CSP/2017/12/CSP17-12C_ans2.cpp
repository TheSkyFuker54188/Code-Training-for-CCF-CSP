// 2017年12月 第C题
// Crontab
// 字符串大模拟+时间日期处理
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_leap(int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }

// 全局变量维护当前时间，从 1970-01-01 00:00 星期四 开始
int Y = 1970, M = 1, D = 1, h = 0, m = 0, W = 4;

// 时间“滴答”走一分钟
void tick()
{
    m++;
    if (m == 60)
    {
        m = 0;
        h++;
        if (h == 24)
        {
            h = 0;
            D++;
            W = (W + 1) % 7; // 星期进位，处理好 % 7
            int max_d = days[M];
            if (M == 2 && is_leap(Y))
                max_d = 29;
            if (D > max_d)
            {
                D = 1;
                M++;
                if (M > 12)
                {
                    M = 1;
                    Y++;
                }
            }
        }
    }
}

// 将当前模拟时间打包为 长整数 方便比对大小，比如 201711170032
long long cur_time_val()
{
    return 1LL * Y * 100000000 + M * 1000000 + D * 10000 + h * 100 + m;
} // 1LL ：类型为 long long 的数字 1

map<string, int> to_val;

void init_map()
{
    string mos[] = {"", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    for (int i = 1; i <= 12; i++)
        to_val[mos[i]] = i;
    string wks[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};
    for (int i = 0; i <= 6; i++)
        to_val[wks[i]] = i;
}

int get_val(string s)
{
    if (s[0] >= '0' && s[0] <= '9')
        return stoi(s);
    for (char &c : s)
        c = tolower(c);
    return to_val[s];
}

struct Rule
{
    bool ms[60], hs[24], ds[32], mos[13], ws[7];
    string cmd;
};

// 解析 `*`, `-` 和 `,`
void parse_field(string s, bool *arr, int max_len)
{
    for (int i = 0; i < max_len; i++)
        arr[i] = false;
    if (s == "*")
    {
        for (int i = 0; i < max_len; i++)
            arr[i] = true;
        return;
    }
    stringstream ss(s);
    string part;
    while (getline(ss, part, ','))
    { // C++ 最方便的单字符分割
        int pos = part.find('-');
        if (pos != string::npos)
        {
            int st = get_val(part.substr(0, pos));
            int ed = get_val(part.substr(pos + 1));
            for (int i = st; i <= ed; i++)
                arr[i] = true;
        }
        else
        {
            arr[get_val(part)] = true;
        }
    }
}

int main()
{
    init_map();
    int n;
    long long S, T;
    if (!(cin >> n >> S >> T))
        return 0;

    vector<Rule> rules(n);
    for (int i = 0; i < n; i++)
    {
        string s1, s2, s3, s4, s5;
        cin >> s1 >> s2 >> s3 >> s4 >> s5 >> rules[i].cmd;
        parse_field(s1, rules[i].ms, 60);
        parse_field(s2, rules[i].hs, 24);
        parse_field(s3, rules[i].ds, 32);
        parse_field(s4, rules[i].mos, 13);
        parse_field(s5, rules[i].ws, 7);
    }

    // 从 1970 开始“快进”，直到到达 S
    while (cur_time_val() < S)
        tick();

    // 在 S 到 T 之间进行检测
    while (cur_time_val() < T)
    {
        for (int i = 0; i < n; i++)
        {
            if (rules[i].ms[m] && rules[i].hs[h] && rules[i].ds[D] && rules[i].mos[M] && rules[i].ws[W])
            {
                printf("%04d%02d%02d%02d%02d %s\n", Y, M, D, h, m, rules[i].cmd.c_str());
            }
        }
        tick(); // 检测完当前分钟后，向后走一分钟
    }

    return 0;
}