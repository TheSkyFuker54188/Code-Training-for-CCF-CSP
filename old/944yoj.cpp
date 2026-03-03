#include <iostream>
using namespace std;

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T>
class Vector
{
protected:
    Rank _size;
    int _capacity;
    T *_elem;

public:
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) // 容量为c、规模为s、所有元素初始为0
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v)
            ;
    }
    ~Vector() { delete[] _elem; }

    T &operator[](Rank r) const;

    Rank remove(Rank lo, Rank hi);
    Rank size()
    {
        return _size;
    }
};

template <typename T>
T &Vector<T>::operator[](Rank r) const
{
    if (r < 0 || r >= _size)
    {
        throw out_of_range("Index out of range");
    }
    return _elem[r];
}

template <typename T>
Rank Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi)
        return 0;
    while (hi < _size)
        _elem[lo++] = _elem[hi++];
    _size = lo; // 有必要的话，shrink()
    return hi - lo;
}

int main()
{
    int n, k;
    cin >> n >> k;
    Vector<int> vec(n, n);

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        vec[i] = val;
    }

    int lo, hi, r = vec.size();
    for (int i = 0; i < k; i++)
    {
        cin >> lo >> hi;
        r -= vec.remove(lo, hi);
        //debug: cout << "\nNOW " << r << "\n";
    }
    for (int j = 0; j < r; j++)
        cout << vec[j] << " ";
}
