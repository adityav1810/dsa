#include <iostream>
#include <vector>
using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        /*
        Initialise ListListNode with given data value
        */
        this->val = data;
        this->next = NULL;
    }

    ~ListNode()
    {
        /*
        Destructor which deletes ListNode
        */
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};
void insertAtHead(ListNode *&head, int data)
{
    ListNode *newListNode = new ListNode(data);
    newListNode->next = head;

    head = newListNode;
}
void printLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *reverseLL(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *fwd = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

void insertAtTail(ListNode *&head, ListNode *&tail, int digit)
{
    ListNode *temp = new ListNode(digit);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

ListNode *add(ListNode *head1, ListNode *head2)
{
    ListNode *temp1 = head1;
    ListNode *temp2 = head2;
    ListNode *anshead = NULL;
    ListNode *anstail = NULL;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL || carry != 0)
    {
        int val1 = 0;
        if (temp1 != NULL)
        {
            val1 = temp1->val;
        }
        int val2 = 0;
        if (temp2 != NULL)
        {
            val2 = temp2->val;
        }
        int sum = carry + val1 + val2;
        int onesdigit = sum % 10;
        insertAtTail(anshead, anstail, onesdigit);
        carry = sum / 10;

        if (temp1 != NULL)
        {
            temp1 = temp1->next;
        }
        if (temp2 != NULL)
        {
            temp2 = temp2->next;
        }
        
    }
    return anshead;
}

ListNode *addNumbers(ListNode *head1, ListNode *head2)
{
    // sanity check
    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }
    else if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }

    // reverse both LL
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    // Add each ListNode , store result in new ll
    ListNode *ans = add(head1, head2);
    // reverse resulting ll
    return reverseLL(ans);
}

int main()
{
    ListNode *head = new ListNode(1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    printLinkedList(head);

    ListNode *head2 = new ListNode(2);
    insertAtHead(head2, 8);
    insertAtHead(head2, 2);
    printLinkedList(head2);
    ListNode *ans = addNumbers(head, head2);
    printLinkedList(ans);

    return 0;
}