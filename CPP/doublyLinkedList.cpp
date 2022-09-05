#include<iostream>
using namespace std;

class Node{
    public: 
    int val;
    Node *left;
    Node *right;

    Node(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
     ~Node() {
        int data = this -> val;
        if(right != NULL) {
            delete right;
            right = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }

};

void insertAtHead(Node* &head, Node *&tail,int data){
    // Function to add an element to the head of the linked list
if(head ==NULL){
    Node *newNode = new Node(data);
head = newNode;
tail = newNode;

}
else{
    Node *newNode = new Node(data);
newNode->right =head;
head->left = newNode;
head = newNode;
cout<<"New Node created with data : "<<data<<endl;

}

}

void insertAtTail(Node* &head,Node* &tail,int data){
    Node *newNode = new Node(data);
    tail->right = newNode;
    newNode->left = tail;
    tail = newNode;
}

void insertAtIndex(Node* &head, Node* &tail, int data, int index){
    if(index ==0){
        insertAtHead(head,tail,data);
        return;
    }

Node *temp = head;
    int pos = 1;
    while(pos < index){
temp = temp->right;
pos++;
}
if(temp->right == NULL){
    insertAtTail(head,tail,data);
    return;
}

    Node *newNode = new Node(data);
    newNode->right = temp->right;
    temp->right->left = newNode;
    temp->right = newNode;
    newNode->left = temp;

}

void deleteAtHead(Node *&head,Node*&tail){
    Node *temp = head;
    head = temp->right;
    temp->right = NULL;
    free (temp);
    head->left = NULL;

}

void deleteNode(Node *&head ,Node* &tail,int index){
if(index ==0){
    deleteAtHead(head,tail);
}
Node *curr = head;
Node *prev = NULL;
int pos = 0;
while(pos<index){
    prev = curr;
    curr = curr->right;
    pos ++;
}
curr->left = NULL;
prev ->right = curr->right;
curr->right = NULL;
}


int getLength(Node *head){
    // Function to get length of linked list
    int counter = 1;
    Node *temp = head;
    while(temp->right !=NULL){
        counter ++;
        temp = temp->right;
    }
    return counter;
}
void printlist(Node* head){
    Node * temp = head;
    cout<<"Linked List : ";
    while(temp !=NULL){
        cout<<"| "<<temp->val<<" |->";
        // cout<<"Node address : "<<temp;
        // cout<<" Value : "<<temp->val<<" at address :  "<<temp->right<<endl;
        temp = temp->right;
    }
    cout<<endl;
    // cout<<"Length of Linked List is : "<<getLength(head)<<endl<<endl;
}
void printHeadAndTail(Node* &head,Node* &tail){
    cout<<"head : "<<head->val<<" tail : "<<tail->val<<endl;
}


int main(){
    Node * node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    // printlist(head);
    insertAtHead(head,tail,20);
    // printlist(head);
    // printHeadAndTail(head,tail);
    insertAtTail(head,tail,30);
    printlist(head);
    // printHeadAndTail(head,tail);
    insertAtIndex(head,tail,40,2);
    // printlist(head);
    insertAtIndex(head,tail,1,3);
    printlist(head);
    printHeadAndTail(head,tail);
    deleteAtHead(head,tail);
    printlist(head);
    printHeadAndTail(head,tail);
    deleteNode(head,tail,2);
    printlist(head);
    printHeadAndTail(head,tail);
    // cout<<node1->val<<endl;
    




    return 0;
}