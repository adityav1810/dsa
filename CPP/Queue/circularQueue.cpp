#include <iostream>
#include <queue>
using namespace std;
class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue()
    {
        this->size = 100001;
        this->arr = new int[this->size];
        this->front = -1;
        this->rear = -1;
    }

    void push(int data)
    {
        if ((front == 0 && rear == size) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is FULL";
            return;
        }

        else if (front == -1)
        {
            front = 0;
            rear = 0;
            
        }
        else if (rear == size && front != 0)
        {

            rear = 0;
            
        }
        else
        {
            
            rear++;
        }
        arr[rear] = data;

    }
    void pop()
    {
        if(front == -1 && rear == -1){
            // queue is empty
            cout<<"Queue is empty";

        }
        int ans = arr[front];
        arr[front] = -1;
        
        
        if(front == rear){
//             single element
            front == rear == -1;
            
        }else if(front == size -1){
            front = 0;
            
        }else{
            front ++;
        }
   


    }
    void isEmpty()
    {
    }
    int top()
    {
        return arr[front];
    }
};

int main()
{
    CircularQueue cq;
    cq.push(6);
    cout<<cq.top();
    cout<<cq.top();
    cq.pop();
    cq.push(5);
    cout<<cq.top();
    cq.pop();
    cq.pop();
    cq.pop();

    return 0;
}