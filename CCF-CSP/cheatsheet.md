# Vector

### 初始化

```cpp
vector<int> v(n);      // 长度为 n，默认值为 0
vector<int> v(n, 1);   // 长度为 n，所有元素初始化为 1
vector<int> a{1, 2, 3, 4, 5};
```

### 常用操作

- `c.front()`：返回首元素，$O(1)$
- `c.back()`：返回尾元素，$O(1)$
- `c.push_back(x)`：尾部插入，$O(1)$（均摊）
- `c.pop_back()`：删除尾元素，$O(1)$
- `c.size()`：元素个数，$O(1)$
- `c.empty()`：判空，$O(1)$
- `c.clear()`：清空，$O(n)$
- `c.resize(n, v)`：调整长度
- `c.insert(it, x)`：在迭代器位置插入，$O(n)$
- `c.erase(first, last)`：删除区间 `[first, last)`，$O(n)$
- `c.begin()` / `c.end()`：首迭代器 / 尾后迭代器

```cpp
sort(c.begin(), c.end());

vector<int> a(n + 1);
sort(a.begin() + 1, a.end());  // 对 [1, n] 排序
```

```cpp
vector<int> vi;
vector<int>::iterator it = vi.begin();
```

## Stack

### 常用操作

- `s.push(x)`：入栈，$O(1)$
- `s.pop()`：出栈，$O(1)$
- `s.top()`：访问栈顶，$O(1)$
- `s.empty()`：判空，$O(1)$
- `s.size()`：元素个数，$O(1)$

### 遍历示例

```cpp
stack<int> st;
for (int i = 0; i < 10; ++i) st.push(i);

while (!st.empty()) {
    int tp = st.top();
    st.pop();
}
```

## Queue / Priority Queue

### queue 常用操作

- `q.front()`：队首，$O(1)$
- `q.back()`：队尾，$O(1)$
- `q.push(x)`：入队，$O(1)$
- `q.pop()`：出队，$O(1)$
- `q.size()`：元素个数，$O(1)$
- `q.empty()`：判空，$O(1)$

### priority_queue 说明

优先队列底层通常是堆，每次取优先级最高元素。

- `pq.top()`：访问堆顶，$O(1)$
- `pq.push(x)`：入堆，$O(\log n)$
- `pq.pop()`：出堆，$O(\log n)$
- `pq.size()` / `pq.empty()`：$O(1)$

注意：`priority_queue` 没有 `clear()`。

```cpp
priority_queue<int> pq;  // 默认大根堆
priority_queue<int, vector<int>, greater<int>> minq;  // 小根堆
```

## Map

### 常用操作

- `mp.find(key)`：返回迭代器，不存在则为 `mp.end()`，$O(\log n)$
- `mp.erase(it)`：按迭代器删除
- `mp.erase(key)`：按键删除，$O(\log n)$
- `mp.erase(first, last)`：删除区间
- `mp.size()` / `mp.empty()`：$O(1)$
- `mp.clear()`：清空，$O(n)$
- `mp.insert(...)`：插入键值对
- `mp.begin()` / `mp.end()`：正向迭代器
- `mp.rbegin()` / `mp.rend()`：逆向迭代器
- `mp.count(key)`：存在返回 1，否则 0
- `mp.lower_bound(key)`：第一个 `>= key`
- `mp.upper_bound(key)`：第一个 `> key`

### 遍历示例

```cpp
map<int, int> mp;
mp[1] = 2;
mp[2] = 3;
mp[3] = 4;

for (auto it = mp.begin(); it != mp.end(); ++it) {
    cout << it->first << " " << it->second << "\n";
}

for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
    cout << it->first << " " << it->second << "\n";
}
```

### 补充

- `map`：红黑树实现，有序，空间开销相对更大。
- `unordered_map`：哈希表实现，无序，平均查询更快。
- 查询推荐先判断存在性，再访问值。

## Set

元素不重复，默认从小到大有序。

### 常用操作

- `s.begin()` / `s.end()`：正向迭代器
- `s.rbegin()` / `s.rend()`：逆向迭代器
- `s.size()` / `s.empty()`：$O(1)$
- `s.clear()`：清空，$O(n)$
- `s.insert(x)`：插入
- `s.erase(it)` / `s.erase(key)` / `s.erase(first, second)`：删除
- `s.find(x)`：查找，失败返回 `s.end()`
- `s.count(x)`：存在返回 1，否则 0
- `s.lower_bound(k)`：第一个 `>= k`，$O(\log n)$
- `s.upper_bound(k)`：第一个 `> k`，$O(\log n)$

```cpp
set<int> s1;                    // 升序
set<int, greater<int>> s2;      // 降序
multiset<int> ms;               // 可重复且有序
unordered_set<int> us;          // 无序且唯一
unordered_multiset<int> ums;    // 无序且可重复
```

## Pair

```cpp
p[i].first;
p[i].second;
```

## String

### 基本特性

- 支持比较：`> >= < <= == !=`
- 支持拼接：`+`

### 输入输出

```cpp
string s;
cin >> s;           // 遇空格/回车结束
getline(cin, s);    // 读整行（可含空格）
```

注意：尽量不要混用 `cin/cout` 与 `scanf/printf/getchar/cin.getline()`。

### 常用操作

- 长度：`s.size()` / `s.length()`
- 容量：`s.capacity()` / `s.max_size()`
- 插入：`s.push_back(c)` / `s.insert(pos, x)` / `s.append(str)`
- 删除：`s.erase(it)` / `s.erase(first, last)` / `s.erase(pos, len)` / `s.clear()`
- 替换：`s.replace(...)`
- 子串：`s.substr(pos, n)`
- 排序：`sort(s.begin(), s.end())`（按 ASCII）

### 大小写转换

```cpp
tolower(s[i]);
toupper(s[i]);

transform(s.begin(), s.end(), s.begin(), ::tolower);
transform(s.begin(), s.end(), s.begin(), ::toupper);
```

### 查找函数

- `s.find(str, pos)` / `s.find(c, pos)`
- `s.rfind(str, pos)` / `s.rfind(c, pos)`
- `s.find_first_of(str, pos)`
- `s.find_first_not_of(str, pos)`
- `s.find_last_of(str, pos)`
- `s.find_last_not_of(str, pos)`

---

## 来源说明

本文档内容基于公开资料整理与重排。

原文链接：[https://blog.csdn.net/wbwkwb/article/details/139473649](https://blog.csdn.net/wbwkwb/article/details/139473649)
