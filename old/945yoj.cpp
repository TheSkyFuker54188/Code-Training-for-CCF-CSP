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

    void remove(int num);

    Rank dedup();

    Rank /* Vector<T>:: */ find(T const &e, Rank lo, Rank hi) const
    {
        while ((lo < hi--) && (e != _elem[hi]))
            ;
        return hi;
    }

    Rank size() { return _size; }
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
void Vector<T>::remove(int num)
{
    int lo = num;
    int hi = num + 1;
    while (hi < _size)
        _elem[lo++] = _elem[hi++];
    _size--;
}

template <typename T>
Rank Vector<T>::dedup()
{
    Rank oldSize = _size;
    for (Rank i = 0; i < _size;)
        if (-1 == find(_elem[i], 0, i))
            i++;
        else
            remove(i);
    return oldSize - _size;
}

int main()
{
    int n;
    cin >> n;
    Vector<int> vec(n, n);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        vec[i] = val;
    }
    vec.dedup();
    cout << vec.size() << "\n";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}
