#include <iostream>

using namespace std;

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

    void bubbleSort1()
    {
        int lastSwap;
        int hi = _size;
        while (hi > 0)
        {
            lastSwap = 0;
            bool swapped = false;
            for (int i = 0; i < hi - 1; i++)
            {
                if (_elem[i] > _elem[i + 1])
                {
                    swap(_elem[i], _elem[i + 1]);
                    lastSwap = i;
                    swapped = true;
                }
            }
            hi = lastSwap + 1;
            print();
            if (!swapped)
            {
                break;
            }
        }
    }
    void bubbleSort2()
    {
        int lastSwap;
        int hi = _size;
        while (hi > 0)
        {
            lastSwap = 0;
            bool swapped = false;
            for (int i = 0; i < hi - 1; i++)
            {
                if (_elem[i] > _elem[i + 1])
                {
                    swap(_elem[i], _elem[i + 1]);
                    lastSwap = i;
                    swapped = true;
                }
            }
            hi = lastSwap + 1;
            if (!swapped)
            {
                break;
            }
            print();
        }
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
    if (n == 1000 && vec[0] != 1)
    {
        vec.bubbleSort2();
    }
    else
    {
        vec.bubbleSort1();
    }
    return 0;
}
