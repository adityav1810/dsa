#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    if (q.empty())
    {
      return;
    }
    else
    {
        int num = q.front();
        q.pop();
        reverseQueue(q);
        q.emplace(num);
    }
}

void printQ(queue<int> q)
{
    if (q.empty())
    {
        // cout<<"Empty";
        return;
    }
    int num;
    while (!q.empty())
    {
        num = q.front();
        q.pop();
        cout << num << " ";
    }
    q.push(num);
}

int main()
{
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    // printQ(q);
    cout<<q.front();
    cout<<endl;
    reverseQueue(q);
    // printQ(q);
    cout<<q.front()<<endl;

    return 0;
}