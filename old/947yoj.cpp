#include <iostream>
#include <algorithm>
#include <unordered_set> // 引入 unordered_set
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
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v)
            ;
    }
    ~Vector() { delete[] _elem; }

    T &operator[](Rank r) const;

    void remove(int num);
    Rank dedup();
    Rank find(T const &e, Rank lo, Rank hi) const;
    void sort();

    Rank size() { return _size; }
    Rank capacity() { return _capacity; }
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
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const
{
    while (lo < hi)
    {
        Rank mid = lo + (hi - lo) / 2;
        if (_elem[mid] == e)
            return mid;
        else if (_elem[mid] < e)
            lo = mid + 1;
        else
            hi = mid;
    }
    return -1; // not found
}

template <typename T>
void Vector<T>::sort()
{
    std::sort(_elem, _elem + _size);
}

template <typename T>
Rank Vector<T>::dedup()
{
    std::unordered_set<T> seen;
    Rank newSize = 0;

    for (Rank i = 0; i < _size; i++)
    {
        if (seen.find(_elem[i]) == seen.end()) // 如果元素未见过
        {
            seen.insert(_elem[i]);
            _elem[newSize++] = _elem[i]; // 保留这个元素
        }
    }
    _size = newSize; // 更新大小
    return _size;    // 返回新大小
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
    vec.sort();
    vec.dedup();

    cout << vec.capacity() - vec.size() << "\n"; // 输出去重后剩余的容量
    return 0;
}
