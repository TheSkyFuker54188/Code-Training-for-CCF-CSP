#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

// 终极优化版埃拉托斯特尼筛法，只筛奇数，使用分段法
void sieveOfEratosthenes(int n) {
    if (n >= 2) {
        printf("2\n");  // 先输出2，因为它是唯一的偶数素数
    }
    
    int limit = (n - 1) / 2;  // 只处理奇数，从3开始
    vector<bool> isPrime(limit + 1, true);  // 标记奇数是否为素数

    // 只标记奇数，对于每个奇数i，对应的是2*i+1
    for (int i = 1; i <= sqrt(n) / 2; ++i) {
        if (isPrime[i]) {
            int prime = 2 * i + 1;
            for (int j = 2 * i * (i + 1); j <= limit; j += prime) {
                isPrime[j] = false;  // 标记奇数 prime 的倍数为非素数
            }
        }
    }

    // 输出所有标记为素数的奇数
    for (int i = 1; i <= limit; ++i) {
        if (isPrime[i]) {
            printf("%d\n", 2 * i + 1);  // 输出奇数素数
        }
    }
}

int main() {
    int n;
    // 输入正整数 n
    cin >> n;
    // 调用筛法输出所有小于等于 n 的素数
    sieveOfEratosthenes(n);

    return 0;
}
