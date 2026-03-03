#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, bool &swapped)
{
    int last = lo;
    swapped = false;
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            last = lo;
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    bool swapped;
    do
    {
        bubbleSort(arr, n, swapped);
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    } while (swapped);

    delete[] arr;
    return 0;
}
