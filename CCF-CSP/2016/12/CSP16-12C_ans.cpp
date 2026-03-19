// 2016年12月 第C题
// 算法 + 数据结构）

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// 辅助函数：解析带等级的权限字串，如果是 name:level，返回 true 并提取两者；否则返回 false。
bool parse_privilege(const string &s, string &name, int &level)
{
    size_t pos = s.find(':');
    if (pos != string::npos)
    {
        name = s.substr(0, pos);
        level = stoi(s.substr(pos + 1));
        return true;
    }
    name = s;
    level = -1; // -1 表示无等级权限
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p;
    if (!(cin >> p))
        return 0;

    // 存储系统中定义的所有权限，key为权限名，value为-1表示无等级，>=0表示是分等级权限
    map<string, int> all_privileges;
    for (int i = 0; i < p; ++i)
    {
        string s;
        cin >> s;
        string name;
        int level;
        if (parse_privilege(s, name, level))
        {
            all_privileges[name] = 1; // 仅标记这是带等级权限
        }
        else
        {
            all_privileges[name] = -1;
        }
    }

    int r;
    cin >> r;
    // 角色表：角色名 -> { 权限名 -> 权限等级 }
    map<string, map<string, int>> roles;
    for (int i = 0; i < r; ++i)
    {
        string role_name;
        int s_count;
        cin >> role_name >> s_count;
        for (int j = 0; j < s_count; ++j)
        {
            string s;
            cin >> s;
            string name;
            int level;
            parse_privilege(s, name, level);
            // 对于相同权限名字，保留最大的等级
            if (roles[role_name].count(name))
            { //* 在这个权限表里查 name 这个键是否存在；返回 1：存在；返回 0：不存在
                roles[role_name][name] = max(roles[role_name][name], level);
            }
            else
            {
                roles[role_name][name] = level;
            }
        }
    }

    int u;
    cin >> u;
    // 用户表：用户名 -> { 权限名 -> 权限等级 }  （将角色的权限合并）
    map<string, map<string, int>> users;
    for (int i = 0; i < u; ++i)
    {
        string user_name;
        int t_count;
        cin >> user_name >> t_count;
        for (int j = 0; j < t_count; ++j)
        {
            string role_name;
            cin >> role_name;
            // 将 role_name 的权限合并给 user_name
            for (map<string, int>::const_iterator it = roles[role_name].begin(); it != roles[role_name].end(); ++it)
            {
                const string &name = it->first;
                int level = it->second;
                if (users[user_name].count(name))
                {
                    users[user_name][name] = max(users[user_name][name], level);
                }
                else
                {
                    users[user_name][name] = level;
                }
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        string user_name, query_priv;
        cin >> user_name >> query_priv;

        string q_name;
        int q_level;
        bool is_ranked_query = parse_privilege(query_priv, q_name, q_level);

        // 如果用户不存在，或者根本不包含对应的权限名
        if (!users.count(user_name) || !users[user_name].count(q_name))
        {
            cout << "false\n";
            continue;
        }

        int user_level = users[user_name][q_name];

        if (is_ranked_query)
        {
            // 分等级权限的带等级查询
            if (user_level >= q_level)
            {
                cout << "true\n";
            }
            else
            {
                cout << "false\n";
            }
        }
        else
        {
            // 查询本身未带等级
            if (all_privileges[q_name] == -1)
            {
                // 不分等级权限
                cout << "true\n";
            }
            else
            {
                // 分等级权限的不带等级查询：输出它的实际等级
                cout << user_level << "\n";
            }
        }
    }

    return 0;
}
