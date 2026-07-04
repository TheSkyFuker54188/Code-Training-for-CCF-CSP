//? 给定一张有向图，判断是否存在一个合法的拓扑序列
#include <iostream>
#include <vector>

using namespace std;
/* 在算法讲解的时候，我们的依赖关系是正的，每次根据后驱寻找前驱。
但是代码实现过程中，通过邻接表找前驱并不好实现，真正好实现的是通过前驱找后驱
所以将关系反着来建边，这样才能更方便的通过邻接表寻找那些依赖的关系。
* 比如：[a,b] : 学a之前先学b，也就是先b才能a，于是有b->a
*/

int main()
{
    int numCourses;
    int m;
    cin>>numCourses>>m;
    // edges[x] 存放  "以 x 为先修课的所有后续课程"
    vector<vector<int>> edges(numCourses);

    // inDegree[i] 表示学习课程 i 之前，还需要完成多少门先修课
    vector<int> inDegree(numCourses, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[b].push_back(a);
        inDegree[a]++;
    }

    /// 所有入度为 0 的课程，都可以最开始学习
    vector<int> q;
    for (int i = 0; i < numCourses; i++)
        if (inDegree[i] == 0)
            q.push_back(i);

    int count = 0;

    while (!q.empty())
    {
        int u = q.back();
        q.pop_back();
        count++;

        for (int v : edges[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push_back(v);
        }
    }

    if (count == numCourses)
        cout << "true";
    else
        cout << "false";
}