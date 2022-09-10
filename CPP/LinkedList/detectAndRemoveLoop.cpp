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
Node * floydCycleDetect(Node *&head)
{

    Node *fast = head;
    Node *slow = head;
    while(slow !=NULL && fast !=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout<<"CYCLE DETECTED";
            return slow;
        }
    }
    return NULL;
}


Node * cycletDetectionMap(Node *head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    map<Node *,bool> visited;
    Node *temp = head;
    while(temp !=NULL){
        if(visited[temp] == true){
            return temp;
        }
        visited[temp ] = true;
        temp = temp->next;
    }
return NULL;
}


Node * getStartingNode(Node *head){
    Node *intersectingnode = floydCycleDetect(head);
    Node *slow = head;
    while(slow !=intersectingnode){
        slow = slow->next;
        intersectingnode = intersectingnode->next;
    }
    cout<<"FOUND LOOP STARTING AT : "<<slow->val<<endl;
    return slow;
}
void removeLoop(Node *head){
    Node *startnode= getStartingNode(head);
    Node *temp = startnode;

    while(temp->next !=startnode){
 
        temp = temp->next;
    }
    cout<<temp->val<<endl;
    temp->next = NULL;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertNode(head, 3);
    insertNode(head, 5);
    insertNode(head, 7);
    insertNode(head, 9);
    createLoop(head, tail);
    insertNode(head, 11);
    insertNode(head, 13);
// cout<<"Linked List is : "<<endl;
    // print(head);
    // printLinkedList(head);
    
// Uncomment next line to create loop in Linked List
    //  createLoop(head, tail);


// Choose which algorithm to use: 

//     cout<<floydCycleDetect(head)<<endl;
//     cout<<cycletDetectionMap(head)<<endl;
// getStartingNode(head);
removeLoop(head);
print(head);
cout<<"Check for LOOP : ";
    cout<<floydCycleDetect(head)<<endl;
    return 0;
}