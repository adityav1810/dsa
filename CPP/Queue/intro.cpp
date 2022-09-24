#include <iostream>
#include <queue>
using namespace std;

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
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.size();
    q.pop();
    cout << q.size();
    q.push(1);
    q.push(3);
    q.push(4);
    q.push(25);
    q.pop();
    cout << q.front() << endl;
    printQ(q);
  cout << q.front() << endl;
    return 0;
}