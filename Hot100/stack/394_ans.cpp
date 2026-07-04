#include <iostream>
#include <vector>
#include <string>    // stoi
#include <cctype>    // isdigit
#include <algorithm> // reverse

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<char> stack;

    for (char c : s)
    {
        if (c != ']')
        {
            stack.push_back(c);
        }
        else
        {
            // 1. 取出括号内的字符串
            string now_str;
            while (stack.back() != '[')
            {
                now_str += stack.back();
                stack.pop_back();
            }
            stack.pop_back(); // 弹出 '['

            // 栈中取出的顺序是反的，反转得到正确顺序
            reverse(now_str.begin(), now_str.end());

            // 2. 取出左括号前的数字
            string num_str;
            while (!stack.empty() && isdigit(stack.back()))
            {
                num_str += stack.back();
                stack.pop_back();
            }
            reverse(num_str.begin(), num_str.end());
            int num = stoi(num_str);

            // 3. 将解码后的字符串按字符压回栈中
            for (int i = 0; i < num; ++i)
            {
                for (char ch : now_str)
                {
                    stack.push_back(ch);
                }
            }
        }
    }

    // 栈中剩余字符即为最终结果
    string result;
    for (char c : stack)
    {
        result += c;
    }

    cout << result << endl;
    return 0;
}