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


Node* reverseK(Node *head,int k){

    // Base case
    if(head == NULL){
        return NULL;
    }

    int count = 0;
    Node *prev= NULL;
    Node *curr = head;
    Node *fwd = NULL;

    while(count < k && curr != NULL){
        // reverse first K elements
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        count ++;
    }
    if(fwd !=NULL){
        head->next = reverseK(fwd,k);
    }
        return prev;

}



int main(){
    Node *head=NULL;
    insertatHead(head,9);
    insertatHead(head,8);
    insertatHead(head,11);
    insertatHead(head,3);
    insertatHead(head,5);
    print(head);
    print(reverseK(head,3));


    return 0;

}