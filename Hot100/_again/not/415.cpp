#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    string n1;
    string n2;
    cin >> n1 >> n2;
    /* cout << n1 << '\n'
         << n2; */
    int p1 = n1.size() - 1;
    int p2 = n2.size() - 1;

    bool carry = false;
    stack<int> ans;

    while (p1 >= 0 && p2 >= 0)
    {
        int tem = n1[p1] - '0' + n2[p2] - '0' + carry;
        if (tem >= 10)
            carry = true;
        else
            carry = false;
        tem = tem % 10;
        ans.push(tem);
        p1--;
        p2--;
    }
    while (p1 >= 0)
    {
        int tem = n1[p1] - '0' + carry;
        if (tem >= 10)
            carry = true;
        else
            carry = false;
        tem = tem % 10;
        ans.push(tem);
        p1--;
    }
    while (p2 >= 0)
    {
        int tem = n2[p2] - '0' + carry;
        if (tem >= 10)
            carry = true;
        else
            carry = false;
        tem = tem % 10;
        ans.push(tem);
        p2--;
    }
    if (carry)
        ans.push(1);

    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
}