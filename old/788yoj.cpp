#include <iostream>
#include <vector>
using namespace std;

// 获取数字在特定位的值
int getDigit(long long num, int exp) {
    return (num / exp) % 10;
}

void radixSort(vector<long long>& arr) {
    long long maxNum = arr[0];
    int n = arr.size();
    
    // 找出最大数
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }
    
    // 从低位到高位进行计数排序
    for(long long exp = 1; maxNum/exp > 0; exp *= 10) {
        vector<long long> output(n);
        vector<int> count(10, 0);
        
        // 统计当前位每个数字出现的次数
        for(int i = 0; i < n; i++) {
            count[getDigit(arr[i], exp)]++;
        }
        
        // 计算累计数量
        for(int i = 1; i < 10; i++) {
            count[i] += count[i-1];
        }
        
        // 从后往前遍历,保证稳定性
        for(int i = n-1; i >= 0; i--) {
            output[count[getDigit(arr[i], exp)] - 1] = arr[i];
            count[getDigit(arr[i], exp)]--;
        }
        
        // 把排序结果复制回原数组
        for(int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    radixSort(arr);
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    
    return 0;
}