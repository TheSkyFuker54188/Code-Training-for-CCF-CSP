#include <iostream>
#include <stack>
#include <string>

bool checkParentheses(const std::string &expression)
{
    std::stack<char> s; // 创建一个栈

    for (char ch : expression)
    {
        if (ch == '(')
        {
            s.push(ch); // 遇到左括号入栈
        }
        else if (ch == ')')
        {
            if (s.empty())
            {
                return false; // 右括号没有对应的左括号
            }
            s.pop(); // 出栈
        }
        else if (ch == '@')
        {
            break; // 遇到结束符号
        }
    }

    return s.empty(); // 如果栈为空，则括号匹配
}

int main()
{
    std::string expression;
    std::getline(std::cin, expression); // 读取输入表达式

    if (checkParentheses(expression))
    {
        std::cout << "YES" << std::endl; // 括号匹配
    }
    else
    {
        std::cout << "NO" << std::endl; // 括号不匹配
    }

    return 0;
}
