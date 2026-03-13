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
    cin >> n;

    role hero[2] = {{true, 0, 0, 30}, {true, 1, 0, 30}};
    // hero[1] 先手
    // hero[0] 后手

    role follower[8]; // 1~7 valid only

    bool p_handside = true;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        getline(cin, tmp);
        cin.ignore();
        ss[i] << tmp;

        ss[i] >> action[i];
        if (action[i] == "summon")
        {
            int pos;
            int dam;
            int hp;
            ss[i] >> pos;
            ss[i] >> dam;
            ss[i] >> hp;
            for (int p = 6; p <= pos; p--)
            {
                follower[p + 1].pre_side = follower[p].pre_side;
                follower[p + 1].damage = follower[p].damage;
                follower[p + 1].health = follower[p].health;
            }
            follower[pos].pre_side = p_handside;
            follower[pos].damage = dam;
            follower[pos].health = hp;
        }
        else if (action[i] == "attack")
        {
            int attkr;
            int defender;
            ss[i] >> attkr;
            ss[i] >> defender;

            int damged = follower[attkr].damage;
            follower[attkr].health -= damged;
            if (defender != 0)
            {
                follower[defender].health -= damged;
                if (follower[defender].health <= 0)
                {
                    for (int p = defender; p <= 6; p++)
                    {
                        follower[p].pre_side = follower[p + 1].pre_side;
                        follower[p].damage = follower[p + 1].damage;
                        follower[p].health = follower[p + 1].health;
                    }
                    follower[7].pre_side = -1;
                    follower[7].damage = 0;
                    follower[7].health = 0;
                }
            }
            else // defender => hero
            {
                hero[p_handside].health -= damged;
                if (hero[p_handside].health <= 0)
                {
                    if (p_handside == true)
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
    {
        if (follower[i].pre_side == 1)
            pre_hand_cnt++;
        else if (follower[i].pre_side == 0)
            post_hand_cnt++;
    }

    cout << flag << endl;

    cout << hero[1].health << endl;
    cout << pre_hand_cnt << " ";
    for (int i = 1; i <= 7; i++)
    {
        if (follower[i].pre_side == 1)
            cout << follower[i].health << " ";
    }
    cout << endl;

    cout << hero[0].health << endl;
    cout << post_hand_cnt << " ";
    for (int i = 1; i <= 7; i++)
    {
        if (follower[i].pre_side == 0)
            cout << follower[i].health << " ";
    }
    cout << endl;
    return 0;
}
