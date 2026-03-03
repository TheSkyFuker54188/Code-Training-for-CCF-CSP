#include <iostream>
#include <string>
#include <vector>
using namespace std;

string multiply(string num1, string num2)
{
    // 处理特殊情况
    if (num1 == "0" || num2 == "0")
        return "0";

    int len1 = num1.size();
    int len2 = num2.size();

    // 结果最多有 len1 + len2 位
    vector<int> result(len1 + len2, 0);

    // 从低位到高位逐位相乘
    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;

            // 加上之前的进位并更新
            int sum = mul + result[p2];
            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }

    // 构建结果字符串，跳过前导零
    string s = "";
    int i = 0;
    while (i < result.size() && result[i] == 0)
        i++;

    // 将剩余数字转换为字符串
    for (; i < result.size(); i++)
    {
        s += result[i] + '0';
    }

    return s;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << multiply(a, b) << endl;
    return 0;
}
