#include <iostream>
#include <stack>

using namespace std;

#define N 10000;
stack<int> number;

int main()
{
    long long a, c, d, e, result = 0;
    char b;
    cin >> a;
    a %= N;
    number.push(a);
    while (cin >> b >> c)
    {
        c %= N;
        if (b == '*')
        {
            d = number.top();
            number.pop();
            e = (d * c) % N;
            number.push(e);
        }
        else if (b == '+')
        {
            number.push(c);
        }
    }
    while (number.size())
    {
        result += number.top();
        number.pop();
    }
    result %= N;
    cout << result << endl;
    return 0;
}