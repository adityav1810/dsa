#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
void insertNode(Node *&tail, int element, int data)
{

    if (tail == NULL)
    {
        // Add node in empty Linked List
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->val != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deletebyValue(Node *&tail, int value)
{

    // empty list
    if (tail == NULL)
    {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else
    {
        // non-empty

        // assuming that "value" is present in the Linked List
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->val != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node Linked List
        if (curr == prev)
        {
            tail = NULL;
        }

        //>=2 Node linked list
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}
void printLinkedList(Node *tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->val << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
int count_elements(Node *tail)
{
    int counter = 0;
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return 0;
    }

    do
    {
        counter++;
        tail = tail->next;
    } while (tail != temp);

    return counter / 2;
}

void splitList(Node *head)
{
    // cout << head->val<<" : ";
    int size = count_elements(head);
    int pos = 1;
    Node *tail1 = head;
    while (pos < size)
    {
        tail1 = tail1->next;
        pos++;
    }
    // cout<<tail1->val<<endl;

    Node *head2 = tail1->next;
    Node *tail2 = tail1->next;
    // cout<<head2->val<<" : ";
    while(tail2->next !=head){
        tail2 = tail2->next;
    }
    // cout<<tail2->val<<endl;

    tail1->next = head;
    tail2->next = head2;
    printLinkedList(head);
    printLinkedList(head2);
}
int main()
{

    Node *tail = NULL;
    insertNode(tail, 5, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);

    insertNode(tail, 7, 9);
    insertNode(tail, 5, 6);
    insertNode(tail, 9, 10);

    insertNode(tail,3,4);
    // printLinkedList(tail);

    // deletebyValue(tail,3);
    // printLinkedList(tail);
    // deletebyValue(tail,10);
    // printLinkedList(tail);
    // deletebyValue(tail,3);
    printLinkedList(tail);
    Node *head = tail->next;
    splitList(tail);
    // cout << count_elements(tail);
    return 0;
}