#include <iostream>
#include <vector>

class Bitmap {
private:
    std::vector<char> bits;

public:
    // 构造函数：初始化位图大小
    Bitmap(int size) : bits((size + 7) / 8, 0) {}

    // 设置位图中第 k 位
    void set(int k) {
        bits[k >> 3] |= (0x80 >> (k & 0x07));
    }

    // 测试位图中第 k 位是否被设置
    bool test(int k) const {
        return bits[k >> 3] & (0x80 >> (k & 0x07));
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    Bitmap bitmap(1000000000); // 创建一个位图，范围为 [0, 10^9]
    std::vector<int> result;

    // 去重操作，保持原序列顺序
    for (int num : nums) {
        if (!bitmap.test(num)) { // 如果数字未出现过
            bitmap.set(num);     // 将其标记为已出现
            result.push_back(num); // 添加到结果列表
        }
    }

    // 输出去重后的结果
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
