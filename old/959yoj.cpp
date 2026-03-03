#include <iostream>

using namespace std;

typedef int Rank;

template <typename T>
class Vector
{
private:
    int _size;
    T *_elem;

public:
    Vector(int n) : _size(n)
    {
        _elem = new T[n];
    }

    ~Vector()
    {
        delete[] _elem;
    }

    T &operator[](int r) const
    {
        return _elem[r];
    }

    void print()
    {
        for (int i = 0; i < _size; ++i)
        {
            cout << _elem[i] << " ";
        }
        cout << endl;
    }

    void mergeSort(Rank lo, Rank hi)
    {
        if (hi - lo < 2)
            return;
        int mi = (lo + hi) >> 1;
        mergeSort(lo, mi);
        mergeSort(mi, hi);
        merge(lo, mi, hi);
    }

    void merge(Rank lo, Rank mi, Rank hi)
    {
        Rank i = 0;
        T *A = _elem + lo;
        Rank j = 0, lb = mi - lo;
        T *B = new T[lb];
        for(Rank i=0;i<lb)
    }
};

int main()
{
    int n;
    cin >> n;
    Vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    return 0;
}
