#include<iostream>
using namespace std;

class Node{
public:
int val;
Node*next ;

Node(int data){
    this->val = data;
    this->next = NULL;
}
};


void insertAtHead(Node *&head,int data){

    Node *newnode = new Node(data);
    newnode->next = head;
    head = newnode;

}

void print(Node *&head){
    Node *temp= head;
    while(temp !=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;

    }
    cout<<endl;

}
int getlength(Node *head){
    Node *temp = head;
    int counter = 0;
    while(temp !=NULL){

counter ++;
temp = temp->next;
    }
    return counter;
}

int getMid(Node *head, int i){
int pos = 0;
Node *temp =head;
while (pos !=i)
{
    pos ++;
    temp = temp->next;
}
return temp->val;

}

int main(){
Node *head = NULL;
insertAtHead(head,1);
insertAtHead(head,2);
insertAtHead(head,3);
insertAtHead(head,4);
insertAtHead(head,5);
insertAtHead(head,6);
print(head);
int count = getlength(head);
cout<<count<<endl;
if(count%2 == 0){
    // even number of elements
    cout<<getMid(head,count/2);
}
else{
    cout<<getMid(head,(count + 1 )/ 2);

}




    return 0;
}