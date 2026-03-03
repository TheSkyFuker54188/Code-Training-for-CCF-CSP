#include <iostream>
#include <cstring> // 用于 memset 函数

class Bitmap {
private:
    int N;      // 位图大小
    char *M;    // 位图数据

public:
    // 构造函数：初始化位图
    Bitmap(int n = 8) {
        N = (n + 7) / 8;     // 计算需要的字节数
        M = new char[N];
        memset(M, 0, N);     // 将位图初始化为 0
    }

    // 析构函数：释放内存
    ~Bitmap() {
        delete[] M;
        M = nullptr;
    }

    // 设置位图中第 k 位
    void set(int k) {
        M[k >> 3] |= (0x80 >> (k & 0x07));
    }

    // 清除位图中第 k 位
    void clear(int k) {
        M[k >> 3] &= ~(0x80 >> (k & 0x07));
    }

    // 测试位图中第 k 位是否被设置
    bool test(int k) const {
        return M[k >> 3] & (0x80 >> (k & 0x07));
    }
};

int main() {
    int a, b, p, q;
    std::cin >> a >> b >> p >> q;

    Bitmap bitmap(100); // 假设最大整数不会超过 100

    // 将值为 a 和 b 的两个整数加入到空集合中
    bitmap.set(a);
    bitmap.set(b);

    // 将值为 p 的整数从当前集合中移除
    bitmap.clear(p);

    // 判断值为 q 的整数是否在当前集合中，若存在则输出1，反之输出0
    if (bitmap.test(q)) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
}
