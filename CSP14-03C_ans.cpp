#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int opt_type[26]; // 0:不存在 1:无参数 2:有参数
string argument[26];

int main()
{
    string pattern;
    if (!(cin >> pattern))
        return 0;

    // 解析格式字符串
    for (int i = 0; i < pattern.length(); i++)
    {
        if (pattern[i] >= 'a' && pattern[i] <= 'z')
        {
            int idx = pattern[i] - 'a';
            if (i + 1 < pattern.length() && pattern[i + 1] == ':')
            {
                opt_type[idx] = 2;
                i++; // 跳过冒号
            }
            else
            {
                opt_type[idx] = 1;
            }
        }
    }

    int n;
    cin >> n;
    string line;
    getline(cin, line); // 读取掉上一行末尾的换行符

    for (int i = 1; i <= n; i++)
    {
        getline(cin, line);
        stringstream ss(line);
        string token;

        // 重置本次命令行的参数记录
        for (int j = 0; j < 26; j++)
            argument[j] = "";

        // 跳过工具名
        if (!(ss >> token))
        {
            cout << "Case " << i << ":" << endl;
            continue;
        }

        while (ss >> token)
        {
            // 检查是否是选项形式 "-x"
            if (token.length() == 2 && token[0] == '-' && token[1] >= 'a' && token[1] <= 'z')
            {
                int idx = token[1] - 'a';
                if (opt_type[idx] == 0)
                {
                    // 非法选项，停止分析
                    break;
                }
                else if (opt_type[idx] == 1)
                {
                    // 无参选项，标记为已出现（存入非空字符串即可）
                    argument[idx] = "present";
                }
                else if (opt_type[idx] == 2)
                {
                    // 有参选项，尝试读取下一个 token 作为参数
                    string val;
                    if (ss >> val)
                    {
                        argument[idx] = val; // 覆盖之前的参数
                    }
                    else
                    {
                        // 读不到参数，停止分析
                        break;
                    }
                }
            }
            else
            {
                // 既不是合法的选项格式，也不是某个合法带参选项的参数（因为带参选项在上面的分支已经耗掉了一个 token）
                // 碰到类似 "documents" 或非单字母选项 "-abc" 等，停止分析
                break;
            }
        }

        // 格式化输出
        cout << "Case " << i << ":";
        for (int j = 0; j < 26; j++)
        {
            if (argument[j] != "")
            {
                if (opt_type[j] == 1)
                {
                    cout << " -" << (char)(j + 'a');
                }
                else if (opt_type[j] == 2)
                {
                    cout << " -" << (char)(j + 'a') << " " << argument[j];
                }
            }
        }
        cout << endl;
    }

    return 0;
}
