#include <iostream>
#include <queue>
using namespace std;
class Queap
{
public:
    void enqueue(int value)
    {
        mainQueue.push(value);
        while (!maxValues.empty() && maxValues.top() < value)
        {
            maxValues.pop();
        }
        maxValues.push(value);
    }
    void dequeue()
    {
        if (!mainQueue.empty())
        {
            int removed = mainQueue.front();
            mainQueue.pop();
            if (removed == maxValues.top())
            {
                maxValues.pop();
            }
        }
    }
    int getMax()
    {
        return maxValues.top();
    }

private:
    queue<int> mainQueue;
    priority_queue<int> maxValues;
};
int main()
{
    int n;
    cin >> n;
    Queap queap;
    vector<int> results;
    for (int i = 0; i < n; ++i)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int value;
            cin >> value;
            queap.enqueue(value);
        }
        else if (op == 0)
        {
            queap.dequeue();
        }
        else if (op == 2)
        {
            cout << queap.getMax() << endl;
        }
    }
    return 0;
}
