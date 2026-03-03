#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int getPrecedence(char op)
{
    if (op == '+')
        return 1;
    if (op == '*')
        return 2;
    return 0;
}

string infixToRPN(const string &infix)
{
    stack<char> operators;
    stringstream output;
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (isdigit(c))
        {
            output << c;
            while (i + 1 < infix.length() && (isdigit(infix[i + 1]) || infix[i + 1] == ' '))
            {
                output << infix[++i];
            }
            output << ' ';
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                output << operators.top() << ' ';
                operators.pop();
            }
            operators.pop();
        }
        else if (c == '+' || c == '*')
        {
            while (!operators.empty() && operators.top() != '(' && getPrecedence(operators.top()) >= getPrecedence(c))
            {
                output << operators.top() << ' ';
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty())
    {
        output << operators.top() << ' ';
        operators.pop();
    }

    return output.str();
}

int evaluateRPN(const string &rpn)
{
    stack<int> operands;
    stringstream input(rpn);
    string token;
    while (input >> token)
    {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1])))
        {
            int num = atoi(token.c_str());
            operands.push(num);
        }
        else
        {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            if (token == "+")
            {
                operands.push(operand1 + operand2);
            }
            else if (token == "*")
            {
                operands.push(operand1 * operand2);
            }
        }
    }
    return operands.top();
}

int main()
{
    string a;
    getline(cin, a, '@');
    string b = infixToRPN(a);
    int result = evaluateRPN(b);
    cout << b << endl;
    cout << result << endl;
    return 0;
}
