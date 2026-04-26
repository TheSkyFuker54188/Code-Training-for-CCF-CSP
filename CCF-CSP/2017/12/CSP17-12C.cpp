// 2017年12月 第C题
// Crontab
// 字符串大模拟+时间日期处理
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct CurTime
{
    int y, m, d, h, min, w;
};

// 存储一条 cron 规则
struct Rule
{
    bool ms[60], hs[24], ds[32], mos[13], ws[7];
    string cmd;

    Rule()
    {
        fill(ms, ms + 60, false);
        fill(hs, hs + 24, false);
        fill(ds, ds + 32, false);
        fill(mos, mos + 13, false);
        fill(ws, ws + 7, false);
    }
};

int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

map<string, int> monthMap = {
    {"jan", 1}, {"feb", 2}, {"mar", 3}, {"apr", 4}, {"may", 5}, {"jun", 6}, {"jul", 7}, {"aug", 8}, {"sep", 9}, {"oct", 10}, {"nov", 11}, {"dec", 12}};

map<string, int> weekMap = {
    {"sun", 0}, {"mon", 1}, {"tue", 2}, {"wed", 3}, {"thu", 4}, {"fri", 5}, {"sat", 6}};

bool isLeap(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// 格式化输出时间
void printTime(const CurTime &ct)
{
    printf("%04d%02d%02d%02d%02d", ct.y, ct.m, ct.d, ct.h, ct.min);
}

// 将字符串转换为小写
string toLower(string s)
{
    for (char &c : s)
        c = tolower(c);
    return s;
}

long long timeToMins(long long timeStr)
{ // 格式化时间转换为分钟数
    int y = timeStr / 100000000;
    int m = (timeStr / 1000000) % 100;
    int d = (timeStr / 10000) % 100;
    int h = (timeStr / 100) % 100;
    int min = timeStr % 100;

    long long totalDays = 0;
    for (int i = 1970; i < y; ++i)
    {
        totalDays += isLeap(i) ? 366 : 365;
    }
    for (int i = 1; i < m; ++i)
    {
        totalDays += daysInMonth[i];
        if (i == 2 && isLeap(y))
            totalDays++;
    }
    totalDays += d - 1;

    return (totalDays * 24 * 60) + (h * 60) + min;
}

CurTime minsToTime(long long mins)
{ // 分钟数转换为格式化时间
    CurTime ct;
    ct.w = ((mins / (24 * 60)) + 4) % 7; // 1970-01-01 是 Thursday (4)
    ct.min = mins % 60;
    mins /= 60;
    ct.h = mins % 24;
    long long days = mins / 24;

    ct.y = 1970;
    while (true) // 算年数
    {
        int dInY = isLeap(ct.y) ? 366 : 365;
        if (days >= dInY)
        {
            days -= dInY;
            ct.y++;
        }
        else
        {
            break;
        }
    }

    ct.m = 1;
    while (true) // 算月数
    {
        int dInM = daysInMonth[ct.m];
        if (ct.m == 2 && isLeap(ct.y))
            dInM++;
        if (days >= dInM)
        {
            days -= dInM;
            ct.m++;
        }
        else
        {
            break;
        }
    }
    // 算天数
    ct.d = days + 1;

    return ct;
}

// 提取一个 token 的数值（可能包含英文缩写）
int getVal(string s, bool isWeek)
{
    if (s[0] >= '0' && s[0] <= '9')
        return stoi(s);
    s = toLower(s);
    if (isWeek)
        return weekMap[s];
    return monthMap[s];
}

// 解析一个时间域，将结果存入 arr
// maxVal 是该域的最大值+1（例如分钟是 60，月份是 13）
void parseField(string s, bool *arr, int maxVal, bool isWeek)
{
    if (s == "*")
    {
        for (int i = 0; i < maxVal; ++i)
            arr[i] = true;
        return;
    }

    vector<string> parts;
    stringstream ss(s);
    string item;
    while (getline(ss, item, ',')) // 按逗号分割读入
    {
        parts.push_back(item);
    }

    for (string part : parts)
    {
        size_t dash = part.find('-');
        if (dash != string::npos) // 时间区间
        {
            int st = getVal(part.substr(0, dash), isWeek);
            int ed = getVal(part.substr(dash + 1), isWeek);
            for (int i = st; i <= ed; ++i)
                arr[i] = true;
        }
        else // 时间点
        {
            arr[getVal(part, isWeek)] = true;
        }
    }
}

int main()
{
    int n;
    long long s_time, t_time;
    cin >> n >> s_time >> t_time;

    long long startMin = timeToMins(s_time);
    long long endMin = timeToMins(t_time);

    vector<Rule> rules(n);
    for (int i = 0; i < n; ++i)
    {
        string min_str, h_str, d_str, mo_str, w_str;
        cin >> min_str >> h_str >> d_str >> mo_str >> w_str >> rules[i].cmd;

        parseField(min_str, rules[i].ms, 60, false);
        parseField(h_str, rules[i].hs, 24, false);
        parseField(d_str, rules[i].ds, 32, false);
        // 注意月份是 1-12
        parseField(mo_str, rules[i].mos, 13, false);
        parseField(w_str, rules[i].ws, 7, true);
    }

    for (long long cur = startMin; cur < endMin; ++cur)
    {
        CurTime ct = minsToTime(cur);
        for (int i = 0; i < n; ++i)
        {
            // 检查这 5 个条件是否都满足
            if (rules[i].ms[ct.min] &&
                rules[i].hs[ct.h] &&
                rules[i].ds[ct.d] &&
                rules[i].mos[ct.m] &&
                rules[i].ws[ct.w])
            {
                printTime(ct);
                printf(" %s\n", rules[i].cmd.c_str());
            }
        }
    }
}