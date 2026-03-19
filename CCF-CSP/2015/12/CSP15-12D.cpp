// 2015年12月 第D题
// 涉及考点：算法 + 数据结构）

// todo   现代C++标准库中的 std::string 非常强大。
// todo   字符串查找、提取、替换在内部都帮我们封装好了最优算法。
//!     “模板文本替换”问题，避免“逐字符遍历”
#include <iostream>
#include <string>

using namespace std;

const int MAX = 5 + 100;

string line[MAX * 2];
string def[MAX];
string var[MAX];

string tmp_var[MAX];

int main()
{
    int m, n;
    cin >> m >> n;
    cin.ignore(); // 吞掉缓存区中的换行符

    for (int i = 0; i < m; i++)
    {
        getline(cin, line[i]);
    }

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> def[i];
        getline(cin, tmp_var[i]);
    }

    // 我们用 find 寻找双引号的位置，安全地提取双引号中间的内容
    for (int i = 0; i < n; i++)
    {
        int startPos = tmp_var[i].find('"'); //* find()从左向右找
        int endPos = tmp_var[i].rfind('"');  //* find()从右向左找
        if (startPos != string::npos && endPos != string::npos && startPos < endPos)
        { //* 找不到就返回 string::npos
            var[i] = tmp_var[i].substr(startPos + 1, endPos - startPos - 1);
        } //* substr(start_idx, substr_length) 函数截取
    }

    // 核心思想：利用 string::find 和 string::replace 在现有的字符串上做无缝替换
    for (int i = 0; i < m; i++)
    {
        int pos = 0;

        // 查找 "{{ "，因为题目说了 "{{ " 中间有空格
        while ((pos = line[i].find("{{ ", pos)) != string::npos)
        {
            // 找到对应的 " }}" 结尾
            int endPos = line[i].find(" }}", pos);
            if (endPos == string::npos)
            {
                pos += 3; // 找不到匹配的 }}，向后走跳过这半拉大括号
                continue;
            }

            // 提取出变量名（"{{ " 占了 3 个字符）
            string varName = line[i].substr(pos + 3, endPos - pos - 3);

            // 查找这个变量名对应的值
            string replaceStr = ""; // 如果变量未定义，题目要求替换为空串
            for (int l = 0; l < n; l++)
            {
                if (def[l] == varName)
                {
                    replaceStr = var[l];
                    break;
                }
            }

            // 执行替换：将整段 "{{ VAR }}" 替换成查找到的值
            line[i].replace(pos, endPos - pos + 3, replaceStr);

            // 更新下一次查找字符串的起点
            // 现在字符串已被替换，所以新的起点应该是 原位置 + 替换后文字的长度
            pos = pos + replaceStr.length();
        }
        cout << line[i] << endl;
    }
    return 0;
}

/* 对于这种“模板文本替换”问题，“逐字符遍历”确实是非常不明智的选择。原因有下面三点：

1. **边界条件极易出错**：逐字符遍历意味着你需要人肉维护多重状态机（比如目前匹配到了一个 `{`，接下来的字符是不是 `{`？然后再往后遇到 `}` 是不是成对的 `}`？）。由于数组有界限，你每一小步判断都需要担心会不会发生 `line[i].length()` 越界（就像你代码里发生的 `line[i][j+1]` 越界）。
2. **文本重组极难管理**：被替换的变量名长度是未知的，要替换进去的字符串的值的长度也是未知的。如果你发现了一个变量长度为 `5`，而它要替换的结果长度为 `30`，纯手工下标不仅需要疯狂地移动大数组后半部分的内容，还非常容易吃掉其他字符或者越界。
3. **C++ 标准库提供的黑科技**：现代 C++ 标准库中的 `std::string` 非常强大。这类字符串查找、提取、替换在内部都帮我们封装好了最优算法。手动搞属于“重新造轮子，且造得不圆”。

我已经用 `std::string` 自带的强大工具链帮你将代码在尽可能原汁原味的基础上进行了改造。你可以先看一下编辑器中新更新的代码。

### 接下来，为你详细拆解新方法中使用到的魔法函数与语法：

#### 1. `std::string::find(const string& str, size_t pos = 0)`
*   **作用**：在当前字符串中，从位置 `pos` 开始向右寻找子串 `str` 第一次出现的位置。如果没有给定 `pos`，默认就是从头 `0` 开始找。
*   **返回值**：如果找到了，返回它起点所在字符的下标。如果整个字符串找不到，就会返回一个特殊的常量叫 **`string::npos`** (意思是 "No Position"，它实际上是一个极其巨大的非负数：`18446744073709551615`)。
*   **代码解读**：
    ```cpp
    while ((pos = line[i].find("{{ ", pos)) != string::npos)
    ```
    这条语句非常精髓：它让系统直接冲到下一个 `"{{ "` 的位置并返回起点下标赋值给 `pos`。只要它不是没找到（`!= string::npos`），代表当前还有剩余未替换的模板标签，我们就继续进去处理。如果一直匹配到它等于 `npos`，说明处理完了，这个 `while` 循环就结束了。

#### 2. `std::string::rfind(const string& str)`
*   **作用**：跟 `find` 刚好反过来（`r` 代表 reverse）。它是从右往左寻找目标子串，返回它**最后一次**出现的位置。
*   **代码解读**：
    ```cpp
    // 假设输入值为:  "tom@example.com"
    int startPos = tmp_var[i].find('"');  // 从左往右找，找到左引号
    int endPos = tmp_var[i].rfind('"');   // 从右往左找，找到右引号
    ```
    这样做比自己用循环扫描 `for` 去找标点要靠谱得多，完全规避了中间有奇怪空格的干扰。

#### 3. `std::string::substr(size_t pos, size_t len)`
*   **作用**：获取子串（sub-string）。从下标 `pos` 开始，截取连续 `len` 个字符，组装成一个新的字符串返回。
*   **代码解读**：
    ```cpp
    string varName = line[i].substr(pos + 3, endPos - pos - 3);
    ```
    我们的 `"{{ "` 刚好占了 3 个字符，所以变量名字的起点就是 `pos + 3`。至于长度，两个词条中间夹在肚子里的字符数，用 `终点 - 起点 - 头标长度(3)` 就能精确拿到 `varName` 字符串。不用再像旧代码那样痛苦地一个字符一个字符复制了！

#### 4. `std::string::replace(size_t pos, size_t len, const string& str)`
*   **作用**：文本替换核弹。它直接把当前字符串从下标 `pos` 往后的 `len` 个字符删掉，并原地换成新字符串 `str`！不用自己操心怎么挪动后续字符的位置，它在底层自动完成了内存位移和拼接。
*   **代码解读**：
    ```cpp
    // pos 是起初找打的 "{{ " 开头。
    // endPos - pos + 3 是 "{{ varName }}" 这个模板块的总长度。
    // 这句话直接把这块模板抠出来，填入 replaceStr，比如 "jerry@example.com"
    line[i].replace(pos, endPos - pos + 3, replaceStr);
    ```

#### 5. `pos` 状态推进更新（非常关键！）
```cpp
pos = pos + replaceStr.length();
```
当你在字符串中间大刀阔斧地替换后，原有的字符串长度和后面的字符位置都会发生改变。
**题目有个要求：“模板不递归生成。如果变量的值中包含 `{{ VAR }}` 的内容，不再做进一步的替换。”**
如果你不更新 `pos` 每次死循环从 `0` 找，如果你替换的内容里恰好又带了个 `{{ }}`，程序就陷入死循环卡死了。所以我们明确告诉程序：替换完了，从**新替换上去的字符串末尾的紧挨着的下一个字符起点 (`pos + replaceLen`)**开始找下一个。

### 总结
有了 `find` 寻找位置、`substr` 剥离内容，以及 `replace` 进行替换，我们可以把各种棘手的“大肠包小肠”的字符串拼接，简化成了干净利落的手术刀式操作，既不担心越界崩溃，代码也易读。希望这样改装能帮到你！你可以跑几组数据试试。
 */