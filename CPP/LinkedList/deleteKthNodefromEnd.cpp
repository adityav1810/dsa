#include<iostream>

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

int getlen(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp !=NULL){
        count ++;
        temp = temp->next;
    }
    return count;
}
Node * delKthFromEnd(Node *head, int key){
   Node* temp;
 
        // First pointer will point to the head of the
        // linked list
        Node* first = head;
 
        // Second pointer will point to the Nth node from
        // the beginning
        Node* second = head;
        for (int i = 0; i < key; i++) {
            // If count of nodes in the given linked list is <= N
            if (second->next == NULL) {
                // If count = N i.e. delete the head node
                if (i == key - 1) {
                    temp = head;
                    head = head->next;
                    free(temp);
                }
                return head;
            }
            second = second->next;
        }
 
        // Increment both the pointers by one until second
        // pointer reaches the end
        while (second->next != NULL) {
            first = first->next;
            second = second->next;
        }
        // First must be pointing to the Nth node from the
        // end by now So, delete the node first is pointing to
        temp = first->next;
        first->next = first->next->next;
        free(temp);
        return head;


}



int main()
{


    Node *node1 = new Node(10);
    Node *head = node1;

    insertAtHead(head,10);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    printLinkedList(head);
    delKthFromEnd(head,2);
    printLinkedList(head);




   
    return 0;
}