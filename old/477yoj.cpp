#include <iostream>

using namespace std;
int n;

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
bool bubble(T *arr, int lo, int hi)
{
    bool sorted = true;
    while (++lo < hi)
    {
        if (arr[lo - 1] < arr[lo])
        {
            sorted = false;
            Swap(arr[lo - 1], arr[lo]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return sorted;
}

template <typename T>
void bubbleSort(T *arr, int lo, int hi)
{
    while (!bubble(arr, lo, hi--))
        ;
}

int main()
{
    cin >> n;
    int val, arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr[i] = val;
    }
    bubbleSort<int>(arr, 0, n - 1);
}
