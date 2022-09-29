#include <iostream>
#include <queue>
using namespace std;
class Deque
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    bool push_front(int val)
    {
        // queue is full
        if (((front == 0 && rear == size - 1)) || (rear = (front - 1) % (size - 1)))
        {
            return false;
        }
        //  queue is empty
        else if (front == -1)
        {
            front = rear = 0;
        }
        // maintain cyclic nature
        else if ((front == 0) && (rear != size - 1))
        {
            front = size - 1;
        }
        else
        { // normal case
            front--;
        }
        arr[front] = val;
        return true;
    }
    bool push_rear(int val)
    {

        // list is full
        if (((front == 0) && (rear == size - 1)) || (rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        // list is empty
        else if (front == -1)
        {
            rear = front = 0;
        }
        // maintain cycle
        else if ((rear == size - 1) && (front != 0))
        {
            rear = 0;
        }
        // normal case
        else
        {
            rear++;
        }
        arr[rear] = val;
        return true;
    }

    bool pop_front()
    {
        if (front == -1)
        {
            // empty list
            return false;
        }
        int ans = arr[front];
        arr[front] = -1;
        // single element
        if (front == rear)
        {
            front = rear = -1;
        }
        // maintain cycle
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return true;
    }

    bool pop_rear()
    {
        // list empty
        if (front == -1)
        {
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        // single element present
        if (front == rear)
        {
            front = rear = -1;
        }
        // maintain cycle
        else if ((rear == size - 1) && (front != 0))
        {
            rear = 0;
        }
        // normal case
        else
        {
            rear--;
        }
        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if ((front == 0 &&rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Deque dq(3);
    dq.push_front(6);
    dq.push_rear(3);
    cout << dq.getFront();
    cout << dq.getRear();
    dq.pop_rear();
    cout << dq.getFront();
    dq.pop_rear();
    cout << dq.getRear();
    
    return 0;
}