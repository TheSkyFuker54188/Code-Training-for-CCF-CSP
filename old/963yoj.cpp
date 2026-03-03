#include <iostream>
#include <string>
#include <cmath>

int convertToDecimal(const std::string &num, int base)
{
    int decimalValue = 0;
    int length = num.size();

    for (int i = 0; i < length; ++i)
    {
        char digit = num[length - 1 - i]; // 从右到左处理
        int value;

        // 处理数字和字母
        if (digit >= '0' && digit <= '9')
        {
            value = digit - '0';
        }
        else if (digit >= 'A' && digit <= 'F')
        {
            value = digit - 'A' + 10;
        }
        else
        {
            throw std::invalid_argument("Invalid digit in number");
        }

        // 计算十进制值
        decimalValue += value * static_cast<int>(pow(base, i));
    }

    return decimalValue;
}

std::string convertFromDecimal(int decimalValue, int base)
{
    std::string result;

    do
    {
        int remainder = decimalValue % base;
        char digit;

        // 处理数字和字母
        if (remainder < 10)
        {
            digit = '0' + remainder;
        }
        else
        {
            digit = 'A' + (remainder - 10);
        }

        result = digit + result; // 逆序构造结果
        decimalValue /= base;
    } while (decimalValue > 0);

    return result.empty() ? "0" : result;
}

int main()
{
    int n, m;
    std::string number;

    // 读取输入
    std::cin >> n;      // 原进制
    std::cin >> number; // 原进制数
    std::cin >> m;      // 目标进制

    // 转换为十进制
    int decimalValue = convertToDecimal(number, n);

    // 从十进制转换到目标进制
    std::string result = convertFromDecimal(decimalValue, m);

    // 输出结果
    std::cout << result << std::endl;

    return 0;
}
