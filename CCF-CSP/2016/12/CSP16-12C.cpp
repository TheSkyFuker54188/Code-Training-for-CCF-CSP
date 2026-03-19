// 2016年12月 第C题
// 涉及考点：算法 + 数据结构）

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

inline bool parse(const string &s, string &name, int &level)
{ // 带等级：true    不带等级：false
    size_t pos = s.find(':');
    if (pos != string::npos)
    {
        name = s.substr(0, pos);
        level = stoi(s.substr(pos + 1));
        return true;
    }
    name = s;
    level = -1; // 无等级
    return false;
}

int main()
{
    int p;
    cin >> p;

    map<string, int> privilege;
    for (int i = 0; i < p; i++)
    {
        string s;
        cin >> s;
        string name;
        int level;
        if (parse(s, name, level))
        {
            privilege[name] = level;
        }
        else
        {
            privilege[name] = -1;
        }
    }

    int r;
    cin >> r;
    map<string, map<string, int>> role;
    for (int i = 0; i < r; i++)
    {
        string role_name;
        int s_cnt;
        cin >> role_name >> s_cnt;
        for (int j = 0; j < s_cnt; j++)
        {
            string s;
            cin >> s;
            string name;
            int level;
            parse(s, name, level);
            if (role[role_name].count(name))
            {
                role[role_name][name] = max(role[role_name][name], level);
            }
            else
            {
                role[role_name][name] = level;
            }
        }
    }

    int u;
    cin >> u;
    map<string, map<string, int>> user;
    for (int i = 0; i < u; i++)
    {
        string user_name;
        int t_cnt;
        cin >> user_name >> t_cnt;
        for (int j = 0; j < t_cnt; j++)
        {
            string role_name;
            cin >> role_name;
            //* 将 role_name 的权限合并给 user_name
            for (auto it = role[role_name].begin(); it != role[role_name].end(); ++it)
            { //* it的实际类型为 map<string, int>::const_iterator
                const string &name = it->first;
                int level = it->second;
                if (user[user_name].count(name))
                {
                    user[user_name][name] = max(user[user_name][name], level);
                }
                else
                {
                    user[user_name][name] = level;
                }
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string user_name, query_priv;
        cin >> user_name >> query_priv;

        string q_name;
        int q_level;
        bool level_query = parse(query_priv, q_name, q_level);

        //* 用户不存在  ||  权限名不存在
        if (!user.count(user_name) || !user[user_name].count(q_name))
        {
            cout << "false\n";
            continue;
        }

        int user_level = user[user_name][q_name];

        if (level_query)
        {
            if (user_level >= q_level)
                cout << "true\n";
            else
                cout << "false\n";
        }
        else
        {
            // 此处需要注意检查：如果该权限原本确实是不带等级的（为-1）
            if (privilege.count(q_name) && privilege[q_name] == -1)
                cout << "true\n";
            else
                cout << user_level << "\n";
        }
    }

    return 0;
}