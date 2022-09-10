#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node(int data){
        this->val = data;
        this->next = NULL;
    }

};


void print(Node *head){

    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;

}
void insertatHead(Node *&head,int data){
    if(head ==NULL){
        // EMPTY LINKED LIST
        Node * newNode = new Node(data);
    }

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

int isCircular(Node *head){
if (head == NULL|| head->next == NULL){
    return 0;
}
Node *temp = head->next;
while(temp !=NULL && temp !=head){
    temp = temp->next;
}
if (temp == head){
    return 1;
}
return 0;
}


void insertcircularLL(Node *&tail,int element,int data){
    if(tail ==NULL){
        // Add node in empty Linked List
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        Node *curr = tail;
        while(curr->val !=element){
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}



void printcircular(Node *tail){
        Node *temp = tail;
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
    do{
        cout<<tail->val<<" ";
        tail =tail->next;
    }while(tail!=temp);
    cout<<endl;
}


int main(){
    Node *tail = NULL;
    insertcircularLL(tail,5,3);
    insertcircularLL(tail,3,5);
    insertcircularLL(tail,5,7);
    
    insertcircularLL(tail,7,9);
    insertcircularLL(tail,5,6);
    insertcircularLL(tail,9,10);
    
    insertcircularLL(tail,3,4);

    // print(head);

    printcircular(tail);

    cout<<isCircular(tail->next);


    return 0;

}