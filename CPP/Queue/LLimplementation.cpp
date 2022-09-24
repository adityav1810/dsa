#include <iostream>
using namespace std;
/*
Implementation of Queue using Linked List
Queue follows First In First Out (FIFO)
maintain 2 ptrs, front and rear
push() : new element is added at rear;
pop() : first element at front is popped out;

*/

// create Node Struct

struct Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

void push(Node *&front, Node *&rear, int data)
{
    if (front == NULL)
    {
        Node *newNode = new Node(data);
        front = newNode;
        rear = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        rear->next = newNode;
        rear = newNode;
    }
}


void pop(Node *&front,Node *&rear){
    if(front == NULL){
        cout<<"Queue is empty";
        return;
    }
    
        Node *temp  =front;
        front = front->next;
    
    if(front == NULL){
        rear = NULL;

    }
        free(temp);
    
}


void printQueue(Node *front)
{
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *front = NULL;
    Node *rear = NULL;

    push(front, rear, 2);
    push(front, rear, 4);
    push(front, rear, 3);
    push(front, rear, 1);

    printQueue(front);
    
    pop(front,rear);
    
    printQueue(front);

    return 0;
}
