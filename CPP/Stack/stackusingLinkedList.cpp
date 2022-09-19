#include<iostream>
using namespace std;
struct Node{
    
    int val;
    Node *next;

    Node(int data)
    {
        /*
        Initialise Node with given data value
        */
        this->val = data;
        this->next = NULL;
    }

    ~Node()
    {
        /*
        Destructor which deletes node
        */
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }

};
void push(Node *&top,int data){
    Node *newNode = new Node(data);
    if(top == NULL){
    top = newNode;
        return;
    }
    newNode ->next = top;
    top = newNode;

}


void printStack(Node *top){
    while(top !=NULL){
        cout<<top->val<<" ";
        top = top->next;
    }
    cout<<endl;

}
void pop(Node *&top){
    if(top == NULL){
        cout<<"Stack Underflow";
    }
    else{
    Node *temp = top;
    top = top->next;
    free(temp);
    }
    
}

int main(){
Node *top = NULL;
push(top,5);
push(top,6);
push(top,3);
printStack(top);

pop(top);

printStack(top);


    return 0;

}