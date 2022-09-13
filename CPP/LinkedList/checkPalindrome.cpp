#include <iostream>
#include <vector>
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
// bool checkPalindrome(vector<int> arr)
// {
//     int r = arr.size();
//     int c = 0;
//     int n = r - 1;
//     while (c <= n)
//     {
//         if (arr[c] != arr[n])
//         {
//             return 0;
//         }
//         c++;
//         n--;
//     }
//     return 1;
// }
// void checkPal(Node *head)
// {

//     vector<int> arr;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         arr.push_back(temp->val);
//         temp = temp->next;
//     }
//     cout << checkPalindrome(arr);
// }

Node *getmidNode(Node *head)
{

    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *fwd = NULL;
    while (curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }

    return prev;
}

bool checkPal(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    // Find mid of LL
    Node *midNode = getmidNode(head);
    // cout<<midNode->val<<endl;
    // reverse 2nd part of LL

    Node *temp = midNode->next;
    midNode->next = reverseLL(temp);

    // Compare 1st and 2nd Part of LL
    Node *slow = head;
    Node *fast = midNode->next;
    while (fast != NULL)
    {
        if (fast->val != slow->val)
        {

            return false;
        }

        fast = fast->next;
        slow = slow->next;
    }
// change LL to original
    temp = midNode->next;
    midNode->next = reverseLL(temp);
    return true;
}

int main()
{
    Node *head = new Node(1);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printLinkedList(head);
    cout << checkPal(head);

    return 0;
}