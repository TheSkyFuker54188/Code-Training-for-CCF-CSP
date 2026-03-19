// 2016年12月 第C题
// 算法 + 数据结构）

#include <iostream>
#include <string>
#include <algorithm> //std::find(【首 , 末）, 值 )  返回第一个找到元素的idx

using namespace std;

const int MAX = 100 + 1;
const int MAXq = 10000 + 1;

struct Privilege
{
    string category;
    int level = -1;
};

Privilege privilege[MAX];
string role[MAX][MAX];
string user[MAX];
