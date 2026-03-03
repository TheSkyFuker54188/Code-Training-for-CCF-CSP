#include <iostream>
using namespace std;

typedef int Rank;
#define DEFAULT_CAPACITY 3
int sum = 0; // 全局变量用于存储累加结果

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

    void traverse(void (*visit)(T &));

    template <typename VST>
    void traverse(VST &visit);

    Rank size() { return _size; }
};

template <typename T>
void Vector<T>::traverse(void (*visit)(T &))
{
    for (Rank i = 0; i < _size; i++)
        visit(_elem[i]);
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST &visit)
{
    for (Rank i = 0; i < _size; i++)
        visit(_elem[i]);
}

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
void m1(T &e)
{
    e--;
}
template <typename T>
void m2(T &e)
{
    e *= 2;
}
template <typename T>
void m3(T &e)
{
    sum = 0;
    auto addToSum = [](T &e)
    { sum += e; };
}

int main()
{
    int n, m;
    cin >> n >> m;
    Vector<int> vec(n, n);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        vec[i] = val;
    }
    switch (m)
    {
    case 1:
        vec.traverse(m1<int>);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        break;

    case 2:
        vec.traverse(m2<int>);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        break;

    case 3:
        m3(vec[0]);
        vec.traverse([](int &e)
                     { sum += e; });
        cout << sum << endl;
        break;

    default:
        cout << "\n Wrong input for 'm' \n";
    }
}
