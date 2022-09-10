#include <iostream>
#include<map>
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
};
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void insertNode(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {

        head = newNode;
    }
    else
    {

        newNode->next = head;
        head = newNode;
    }
}
bool floydCycleDetect(Node *&head)
{

    Node *fast = head;
    Node *slow = head;
    while(slow !=NULL && fast !=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout<<"CYCLE DETECTED";
            return 1;
        }
    }
    return 0;
}


bool cycletDetectionMap(Node *head){
    if(head == NULL || head->next == NULL){
        return false;
    }
    map<Node *,bool> visited;
    Node *temp = head;
    while(temp !=NULL){
        if(visited[temp] == true){
            return 1;
        }
        visited[temp ] = true;
        temp = temp->next;
    }
return false;
}
void createLoop(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp->next != NULL)

    {
        // cout << temp->val << " ";
        temp = temp->next;
    }
    tail = temp;

    temp->next = head;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertNode(head, 3);
    insertNode(head, 5);
    insertNode(head, 7);
    insertNode(head, 9);
    insertNode(head, 11);
    insertNode(head, 13);
cout<<"Linked List is : "<<endl;
    print(head);
    
// Uncomment next line to create loop in Linked List
     createLoop(head, tail);


// Choose which algorithm to use: 

    cout<<floydCycleDetect(head)<<endl;
    cout<<cycletDetectionMap(head)<<endl;

    return 0;
}