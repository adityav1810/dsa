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
    ~Node(){
        if(this->next !=NULL){
            delete next;
            next = NULL;
        }
    }
};

void insertNode(Node * &tail,int element,int data){

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


void deletebyValue(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> val != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}



void printLinkedList(Node *tail){
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
    insertNode(tail,5,3);
    // insertNode(tail,3,5);
    // insertNode(tail,5,7);
    
    // insertNode(tail,7,9);
    // insertNode(tail,5,6);
    // insertNode(tail,9,10);
    
    // insertNode(tail,3,4);
    // printLinkedList(tail);

    // deletebyValue(tail,3);
    // printLinkedList(tail);
    // deletebyValue(tail,10);
    // printLinkedList(tail);
    deletebyValue(tail,3);
      printLinkedList(tail);
    return 0;

}