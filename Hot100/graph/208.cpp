// 如果只是把每个单词单独塞进列表，每次查询都要从头比对，前缀查询更慢
//* 公共前缀没必要各存一份
#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct Node
{
    array<Node *, 26> next{}; // 26 个小写字母子指针
    bool is_end = false;      // 是否为单词结尾
    Node() { next.fill(nullptr); }
};

Node *root;

Node *walk(const string &s)
{
    Node *cur = root;
    for (char c : s)
    {
        int i = c - 'a';
        if (cur->next[i] == nullptr)
            return nullptr;
        cur = cur->next[i];
    }
    return cur;
}

void insert(const string &word)
{
    Node *cur = root;
    for (char c : word)
    {
        int i = c - 'a';
        if (cur->next[i]==nullptr)
            cur->next[i] = new Node();
        cur = cur->next[i];
    }
    cur->is_end = true;
}

bool search(const string &word)
{
    Node *cur = walk(word);
    if (cur != nullptr)
    {
        if (cur->is_end)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool startsWith(const string &prefix)
{
    Node *yes = walk(prefix);
    if (yes == nullptr)
        return false;
    else
        return true;
}

int main()
{
    root = new Node();

    int n;
    cin >> n;
    string op, word;
    for (int i = 0; i < n; i++)
    {
        cin >> op >> word;
        if (op == "insert")
            insert(word);
        else if (op == "search")
        {
            bool v = search(word);
            if (v)
                cout << "true" << '\n';
            else
                cout << "false" << '\n';
        }
        else if (op == "startsWith")
        {
            bool v = startsWith(word);
            if (v)
                cout << "true" << '\n';
            else
                cout << "false" << '\n';
        }
    }
    return 0;
}