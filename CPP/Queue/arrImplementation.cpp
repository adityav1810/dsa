#include<iostream>
using namespace std;
class Queue{
int *arr;
int qfront;
int rear;
int size;
public:
// define constructor
Queue(){
size = 100001;
arr = new int[size];
qfront = 0;
rear = 0;
}

void push(int data){
    if(rear == size){
        // queue is full
cout<<"Queue is full"<<endl;
    }
    else{
        arr[rear] = data;
        rear ++;

    }

}
int pop(){
    if(qfront == rear){
        cout<<"queue is full"<<endl;
        return -1;
    }
    else{
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront ++;
        if(qfront == rear){
            qfront = 0;
            rear = 0;
        }
        return ans;
    }
}


int front(){
    if(qfront == rear){
        return -1;
    }
    else{
        return arr[qfront];
    }
}

bool isEmpty(){
    if(qfront == rear){
        return true;
    }
    else{
        return false;
    }
}

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    cout<<q.front();
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.isEmpty();
    q.push(10);
    cout<<q.front();
    return 0;
}