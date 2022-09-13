#include <iostream>
using namespace std;

class Node
{

public:
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
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;

    head = newNode;
}
void printLinkedList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void sortlist(Node *head){

    Node *temp = head;
   
    int count0=0;
    int count1 = 0 ;
    int count2 = 0;


while(temp !=NULL){

    if(temp->val == 0){
        count0++;
    }
    else if(temp->val == 1){
        count1++;
    }
    else if(temp->val == 2){
        count2++;
    }
    temp = temp->next;
}
cout<<count0<<count1<<count2<<endl;

Node *temp2 = head;


    while(count0>0){
        temp2->val  = 0;
        temp2 = temp2->next;
        count0--;
    }
    while(count1>0){
        temp2->val  = 1;
        temp2 = temp2->next;
        count1--;
    }
    while(count2>0){
        temp2->val  = 2;
        temp2 = temp2->next;
        count2--;
    }
    printLinkedList(head);



}


int main()
{

    // Node *llnode1 = new Node(2);
    // Node *llnode2 = new Node(5);
    Node *node1 = new Node(0);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head,1);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
        insertAtHead(head,0);
    insertAtHead(head, 0);
    insertAtHead(head, 2);
        insertAtHead(head,1);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
printLinkedList(head);
sortlist(head);
    // cout << "HEAD: " << head->val << " TAIL :" << tail->val<< endl;

    return 0;
}
