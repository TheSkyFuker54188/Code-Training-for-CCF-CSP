#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Game {
    int deadline; // 游戏完成期限
    int penalty;  // 未按时完成的扣款
};

// 比较函数：按扣款从大到小排序
bool compare(const Game& a, const Game& b) {
    return a.penalty > b.penalty;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<Game> games(n);
    for (int i = 0; i < n; i++) {
        cin >> games[i].deadline;
    }
    for (int i = 0; i < n; i++) {
        cin >> games[i].penalty;
    }

    // 按扣款从大到小排序
    sort(games.begin(), games.end(), compare);

    // 标记每个时段是否被占用
    vector<bool> slot(n + 1, false);

    int totalPenalty = 0;

    // 遍历每个游戏，尝试安排到最晚的可用时段
    for (int i = 0; i < n; i++) {
        int deadline = games[i].deadline;
        // 从 deadline 往前找可用的时段
        for (int j = deadline; j >= 1; j--) {
            if (!slot[j]) {
                slot[j] = true; // 占用该时段
                break;
            }
            // 如果找不到可用时段，则累加扣款
            if (j == 1) {
                totalPenalty += games[i].penalty;
            }
        }
    }

    // 输出最终奖励
    cout << m - totalPenalty << endl;

    return 0;
}