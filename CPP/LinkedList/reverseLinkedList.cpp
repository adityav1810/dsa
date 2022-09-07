#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node *next;
    Node(int data){
        this->val = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head,int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void printLL(Node *head){
    Node *temp = head;
    while(temp !=NULL){
    cout<<temp->val<<" ";
    temp = temp->next; 

    }
    cout<<endl;
}

void recursiveReverseLL(Node *&head,Node*curr,Node *prev){

// Recursive Method to Reverse LL

if(curr ==NULL){
    head = prev;
    return;
}

recursiveReverseLL(head,curr->next,curr);
curr->next = prev;


}




void reverseLL(Node* &head){
// Iterative method
    Node *prev = NULL;
    Node *curr = head;
    
    while(curr !=NULL){
Node *fwd = curr->next;

    curr->next = prev;
    prev = curr;
    curr = fwd;

    
    }
    head = prev;
    


}

int main(){
    // Node *node1 = new Node(1);
    Node *head = NULL;

    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);

    printLL(head);
    reverseLL(head);
    printLL(head);
    Node *curr = head;
    Node *prev  = NULL;
    recursiveReverseLL(head,curr,prev);
    printLL(head);


    return 0;
}