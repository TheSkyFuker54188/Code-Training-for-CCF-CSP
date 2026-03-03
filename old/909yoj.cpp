#include <iostream>
#include <vector>
using namespace std;

// 快速选择算法的分区函数
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// 快速选择算法
int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) return arr[left];
    
    int pivotIndex = partition(arr, left, right);
    int count = pivotIndex - left + 1;
    
    if (count == k) return arr[pivotIndex];
    if (count > k) return quickSelect(arr, left, pivotIndex - 1, k);
    return quickSelect(arr, pivotIndex + 1, right, k - count);
}

int main() {
    ios::sync_with_stdio(false);  // 优化输入输出
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << quickSelect(arr, 0, n - 1, k) << endl;
    
    return 0;
}