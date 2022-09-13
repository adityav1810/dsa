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
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *solve(Node *h1, Node *h2)
{

// If h1 has only 1 element
if(h1->next == NULL){
    h1->next = h2;
    return h1;
}

    Node *curr1 = h1;
    Node *next1 = h1->next;
    Node *curr2 = h2;
    Node *next2 = h2->next;
    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->val >= curr1->val) && (curr2->val <= next1->val))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = curr1->next;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return h1;
            }
        }
    }
    return h1;
}
Node *mergeSortedList(Node *head1, Node *head2)
{

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->val <= head2->val)
    {
        return (solve(head1, head2));
    }
    else
    {
        return(solve(head2, head1));
    }

}
int main()
{
    Node *head1 = new Node(5);
    insertAtHead(head1, 4);
    insertAtHead(head1, 1);
    Node *head2 = new Node(5);
    insertAtHead(head2, 3);
    insertAtHead(head2, 2);
    printLinkedList(head1);
    printLinkedList(head2);
    printLinkedList(mergeSortedList(head1,head2));

    return 0;
}