#include <iostream>
#include <vector>

// 归并排序并计算逆序对的函数
long long mergeAndCount(std::vector<int> &arr, std::vector<int> &temp, int left, int mid, int right) {
    int i = left;     // 左半部分的起始索引
    int j = mid + 1;  // 右半部分的起始索引
    int k = left;     // 合并数组的起始索引
    long long invCount = 0;  // 逆序对的数量

    // 合并左右子数组，并统计逆序对
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);  // 统计逆序对
        }
    }

    // 将剩余的左半部分元素拷贝到临时数组
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // 将剩余的右半部分元素拷贝到临时数组
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 将临时数组中的内容拷贝回原数组
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

// 使用归并排序计算逆序对的主函数
long long mergeSortAndCount(std::vector<int> &arr, std::vector<int> &temp, int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        invCount += mergeSortAndCount(arr, temp, left, mid);         // 左半部分的逆序对
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);    // 右半部分的逆序对

        invCount += mergeAndCount(arr, temp, left, mid, right);      // 合并时统计逆序对
    }
    return invCount;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::vector<int> temp(n);

    // 输入列表节点的值
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // 计算逆序对的数量
    long long invCount = mergeSortAndCount(arr, temp, 0, n - 1);

    // 输出逆序对的数量
    std::cout << invCount << std::endl;

    return 0;
}
