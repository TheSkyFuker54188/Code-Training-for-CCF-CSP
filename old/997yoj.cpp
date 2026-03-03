#include <iostream>
#include <vector>
#include <limits>
#include <cstdio>

#define MaxRows 10005

int minIndexForRow[MaxRows];

class Matrix {
private:
    int m, n;
    int *matrix;
    int accessElementCount, accessElementCountLimit;

public:
    Matrix() {
        scanf("%d %d", &m, &n);
        matrix = new int[m * n];
        for (int i = 0; i < m * n; i++) {
            scanf("%d", &matrix[i]);
        }
        accessElementCount = 0;
        accessElementCountLimit = 0.4 * m * n;
    }

    ~Matrix() {
        delete[] matrix;
    }

    int getElement(int row, int col) {
        accessElementCount += 1;
        return matrix[row * n + col];
    }

    bool passAccessElementCountLimit() {
        return accessElementCount <= accessElementCountLimit;
    }

    int getRowNumber() {
        return m;
    }

    int getColNumber() {
        return n;
    }
};

// 找到某一行的最左最小值下标
int findMinIndex(Matrix &matrix, int row, int left, int right) {
    int minIdx = left;
    int n = matrix.getColNumber();
    for (int j = left; j <= right && j < n; ++j) {
        if (matrix.getElement(row, j) < matrix.getElement(row, minIdx)) {
            minIdx = j;
        }
    }
    return minIdx;
}

// 分治法找出所有行的最左最小值下标
void findMinIndices(Matrix &matrix, int top, int bottom, int left, int right) {
    if (top > bottom) return;
    
    int mid = (top + bottom) / 2;
    // 在当前范围 [left, right] 中找出第 mid 行的最小值下标
    int minIdx = findMinIndex(matrix, mid, left, right);
    minIndexForRow[mid] = minIdx;

    // 递归处理上半部分和下半部分
    findMinIndices(matrix, top, mid - 1, left, minIdx);    // 上半部分
    findMinIndices(matrix, mid + 1, bottom, minIdx, right); // 下半部分
}

void solve(Matrix &matrix) {
    int m = matrix.getRowNumber();
    int n = matrix.getColNumber();
    // 使用分治法计算每一行的最左最小值下标
    findMinIndices(matrix, 0, m - 1, 0, n - 1);
}

int main() {
    Matrix matrix{};
    solve(matrix);
    if (matrix.passAccessElementCountLimit()) {
        int m = matrix.getRowNumber();
        for (int i = 0; i < m - 1; ++i) {
            printf("%d ", minIndexForRow[i]);
        }
        printf("%d", minIndexForRow[m - 1]);
    }
    return 0;
}
