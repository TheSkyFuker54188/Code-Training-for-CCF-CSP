#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 递归函数，将指数转换为2的幂次方表示
string convert(int n) {
    if (n == 0) return "2(0)";
    if (n == 1) return "2";
    
    string result;
    int power = 0;
    vector<string> parts;
    
    while (n > 0) {
        if (n % 2 == 1) {
            if (power == 0) {
                parts.push_back("2(0)");
            } else if (power == 1) {
                parts.push_back("2");
            } else {
                parts.push_back("2(" + convert(power) + ")");
            }
        }
        n /= 2;
        power++;
    }
    
    reverse(parts.begin(), parts.end());
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) result += "+";
        result += parts[i];
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << convert(n) << endl;
    return 0;
}