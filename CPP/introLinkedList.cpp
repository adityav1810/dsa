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

void insertAtTail(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = tail->next;
}
void insertAtIndex(Node *&tail, Node *&head, int data, int index)
{

    /*
    Add at position 0
    */
    if (index == 1)
    {
        insertAtHead(head, data);
        return;
    }

    /*
    Add at position index
    */
    int pos = 1;
    Node *temp = head;
    while (pos < index - 1)
    {
        temp = temp->next;
        pos++;
    }
    /*
    Insert in the end
    */
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
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


void deletebyIndex(Node * &tail ,Node * &head, int index){
    // index = 0

    if(index ==1){
        // if index is first element
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
        return;
    }
    else{
        // if index is any element other than 1
        Node *curr = head;
        Node *prev = NULL;
        int pos = 1;
        while(pos<index){
            prev = curr;
            curr = curr->next;
            pos++;

        }

        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
        tail->val = prev->val;
        tail->next = prev->next;

    }



}

int main()
{

    // Node *llnode1 = new Node(2);
    // Node *llnode2 = new Node(5);
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    // insertAtHead(head,10);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    // printLinkedList(head);

    insertAtTail(tail, 9);
    // printLinkedList(head);
    insertAtIndex(tail, head, 2, 1);
    // printLinkedList(head);
    insertAtIndex(tail, head, 0, 4);
    // printLinkedList(head);
    insertAtIndex(tail, head, 2, 5);
    // printLinkedList(head);
    insertAtIndex(tail, head, 11, 8);
    printLinkedList(head);
    cout<<"delete node"<<endl;
    deletebyIndex(tail, head, 8);
    printLinkedList(head);
    

    cout << "HEAD: " << head->val << " TAIL :" << tail->val << endl;
// cout<<head->next->val;
    return 0;
}

/*

//     cout<<"Before Linking Nodes: "<<endl;

//     cout<<"Value : "<<llnode1->val<<" Address : "<<llnode1->next<<endl;
//     cout<<"Value : "<<llnode2->val<<" Address : "<<llnode2->next<<endl;

//     llnode1->next = llnode2;

// cout<<"After Linking Nodes: "<<endl;
// cout<<llnode1<<" "<<llnode2<<" "<<llnode1->next<<endl;
//     cout<<"Value : "<<llnode1->val<<" Address : "<<llnode1->next<<endl;
//     cout<<"Value : "<<llnode2->val<<" Address : "<<llnode2->next<<endl;
*/
