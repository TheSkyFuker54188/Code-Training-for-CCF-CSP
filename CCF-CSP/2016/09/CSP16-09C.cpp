// 2016年09月 第C题
// 涉及考点：算法 + 数据结构）

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int MAX = 1000;
int n;
int flag = 0;

stringstream ss[MAX];
struct role
{
    bool is_hero = false;
    int pre_side = -1;
    int damage = 0;
    int health = 0;
};
string action[MAX];

int main()
{
    // freopen("in.txt", "r", stdin);

    cin >> n;
    cin.ignore();

    role hero[2] = {{true, 0, 0, 30}, {true, 1, 0, 30}};
    // hero[1] 先手
    // hero[0] 后手

    role follower[2][8]; // 1~7 valid only

    bool p_handside = true;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        getline(cin, tmp);
        ss[i] << tmp;

        ss[i] >> action[i];
        /*         cout << "DEBUG:" << tmp << '\n'
                     << action[i] << endl; */
        if (action[i] == "summon")
        {
            int pos;
            int dam;
            int hp;
            ss[i] >> pos;
            ss[i] >> dam;
            ss[i] >> hp;
            for (int p = 6; p >= pos; p--)
            {
                if (follower[p_handside][p].pre_side == -1)
                    continue;
                follower[p_handside][p + 1].pre_side = follower[p_handside][p].pre_side;
                follower[p_handside][p + 1].damage = follower[p_handside][p].damage;
                follower[p_handside][p + 1].health = follower[p_handside][p].health;
            }
            follower[p_handside][pos].pre_side = p_handside;
            follower[p_handside][pos].damage = dam;
            follower[p_handside][pos].health = hp;

            /* cout << "先手: " << endl;
            for (int x = 1; x <= 7; x++)
            {
                if (follower[1][x].pre_side == 1)
                    cout << follower[1][x].health << " " << follower[1][x].damage << " ";
            }
            cout << endl;
            cout << "后手: " << endl;
            for (int x = 1; x <= 7; x++)
            {
                if (follower[0][x].pre_side == 0)
                    cout << follower[0][x].health << " " << follower[0][x].damage << " ";
            }
            cout << endl; */
        }
        else if (action[i] == "attack")
        {
            int attkr;
            int defender;
            ss[i] >> attkr;
            ss[i] >> defender;

            int damged1 = follower[p_handside][attkr].damage;
            int damged2 = 0;
            if (defender != 0)
                damged2 = follower[!p_handside][defender].damage;

            follower[p_handside][attkr].health -= damged2;
            if (follower[p_handside][attkr].health <= 0)
            {
                for (int p = attkr; p <= 6; p++)
                {
                    if (follower[p_handside][p].pre_side == -1)
                        continue;
                    follower[p_handside][p].pre_side = follower[p_handside][p + 1].pre_side;
                    follower[p_handside][p].damage = follower[p_handside][p + 1].damage;
                    follower[p_handside][p].health = follower[p_handside][p + 1].health;
                }
                follower[p_handside][7].pre_side = -1;
                follower[p_handside][7].damage = 0;
                follower[p_handside][7].health = 0;
            }
            if (defender != 0)
            {
                follower[!p_handside][defender].health -= damged1;
                if (follower[!p_handside][defender].health <= 0)
                {
                    for (int p = defender; p <= 6; p++)
                    {
                        if (follower[!p_handside][p].pre_side == -1)
                            continue;
                        follower[!p_handside][p].pre_side = follower[!p_handside][p + 1].pre_side;
                        follower[!p_handside][p].damage = follower[!p_handside][p + 1].damage;
                        follower[!p_handside][p].health = follower[!p_handside][p + 1].health;
                    }
                    follower[!p_handside][7].pre_side = -1;
                    follower[!p_handside][7].damage = 0;
                    follower[!p_handside][7].health = 0;
                }
            }
            else // defender => hero
            {
                hero[!p_handside].health -= damged1;
                if (hero[!p_handside].health <= 0)
                {
                    if (!p_handside == true)
                        flag = -1;
                    else
                        flag = 1;
                    break;
                }
            }
        }
        else // "end"
        {
            p_handside = (!p_handside);
        }
    }
    int pre_hand_cnt = 0;
    int post_hand_cnt = 0;
    for (int i = 1; i <= 7; i++)
        if (follower[1][i].pre_side == 1)
            pre_hand_cnt++;
    for (int i = 1; i <= 7; i++)
        if (follower[0][i].pre_side == 0)
            post_hand_cnt++;

    cout << flag << endl;

    cout << hero[1].health << endl;
    cout << pre_hand_cnt << " ";
    for (int i = 1; i <= 7; i++)
    {
        if (follower[1][i].pre_side == 1)
            cout << follower[1][i].health << " ";
    }
    cout << endl;

    cout << hero[0].health << endl;
    cout << post_hand_cnt << " ";
    for (int i = 1; i <= 7; i++)
    {
        if (follower[0][i].pre_side == 0)
            cout << follower[0][i].health << " ";
    }
    cout << endl;
    return 0;
}

/*
cin >> x
读取下一个“非空白 token”（空格、换行都算分隔符）
不会读入分隔符本身，分隔符留在缓冲区

getline(cin, s)
读取整行直到换行，换行被丢弃，内容放到 s
如果缓冲区第一字符就是换行，会得到空串

cin.ignore(k, '\n')
丢弃最多 k 个字符，直到遇到换行为止（含换行）
常见用法：在 cin >> 后清理残留行尾，再进入 getline 流程

stringstream
把一整行字符串再按空白切 token，适合解析命令行
复用同一个 stringstream 时必须先 clear 再 str(newLine)
*/