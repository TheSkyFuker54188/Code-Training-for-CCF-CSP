#include <algorithm>
#include <iostream>
#include <vector>

void swap(int *arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int *arr, int left, int right)
{
    int j = left - 1;
    for (int i = left; i < right; i++)
    {
        if (arr[i] <= arr[right])
            swap(arr, i, ++j);
    }
    swap(arr, ++j, right);
    return j;
}

int quickSelect(int *arr, int left, int right, int k)
{
    if (left <= right)
    {
        int idx = partition(arr, left, right);
        if ((k - 1) == idx)
            return idx;
        if ((k - 1) > idx)
            return quickSelect(arr, idx + 1, right, k);
        else
            return quickSelect(arr, left, idx - 1, k);
    }
    return -1;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    int idx = quickSelect(arr, 0, n - 1, k);
    std::cout << arr[idx] << std::endl;
    return 0;
}