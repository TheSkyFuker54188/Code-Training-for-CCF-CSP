#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct edge {
    int lson, rson, num, row;
}tree[105];

int cnt = 1, row = 0;
char str[105][605];

void Create(int root, int delta) {
    if (tree[root].num < delta) {
        if (tree[root].rson != -1)
            Create(tree[root].rson, delta);
        else {
            tree[root].rson = cnt;
            tree[cnt++].num = delta;
        }
    }
    else {
        if (tree[root].lson != -1)
            Create(tree[root].lson, delta);
        else {
            tree[root].lson = cnt;
            tree[cnt++].num = delta;
        }
    }
}

int get_dig(int n) {//计算数字的位数
    int cnt = 0;
    while (n) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

void print_1(int root, int col, int num) {//将二叉树存到数组里面
    int pre = num + get_dig(tree[root].num) + (!col ? 1 : 3);
    if (tree[root].rson != -1)//寻找右子树，往上走
        print_1(tree[root].rson, col + 1, pre);
    for (int i = 0; i < num; i++)
        str[row][i] = '.';
    if (!col) {//第一列
        if (tree[root].lson != -1 || tree[root].rson != -1)
            sprintf(str[row] + num, "%d%s", tree[root].num, "-|");
        else sprintf(str[row] + num, "%d", tree[root].num);
    }
    else {
        if (tree[root].lson != -1 || tree[root].rson != -1)
            sprintf(str[row] + num, "%s%d%s", "|-", tree[root].num, "-|");
        else sprintf(str[row] + num, "%s%d", "|-", tree[root].num);
    }  
    tree[root].row = row++;//进入下一行
    if (tree[root].lson != -1)
        print_1(tree[root].lson, col + 1, pre);
}

void print_2(int root, int col, int num) {//往数组里面插入'|'
    int pre = num + get_dig(tree[root].num) + (!col ? 1 : 3);
    if (tree[root].rson != -1) {
        print_2(tree[root].rson, col + 1, pre);
        for (int i = tree[tree[root].rson].row; i < tree[root].row; i++)
            str[i][pre] = '|';
    }
    if (tree[root].lson != -1) {
        print_2(tree[root].lson, col + 1, pre);
        for (int i = tree[tree[root].lson].row; i > tree[root].row; i--)
            str[i][pre] = '|';
    }
}

int main() {
    int delta;
    memset(tree, -1, sizeof(tree));
    scanf("%d", &delta);
    tree[0].num = delta;
    while (~scanf("%d", &delta))
        Create(0, delta);
    row = 0;
    print_1(0, 0, 0);
    print_2(0, 0, 0);
    for (int i = 0; i < row; i++)
        printf("%s\n", str[i]);
    return 0;
}