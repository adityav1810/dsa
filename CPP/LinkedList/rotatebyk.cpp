#include <iostream>
using namespace std;

class listnode
{

public:
    int val;
    listnode *next;

    listnode(int data)
    {
        /*
        Initialise listnode with given data value
        */
        this->val = data;
        this->next = NULL;
    }

    ~listnode()
    {
        /*
        Destructor which deletes listnode
        */
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(listnode *&head, int data)
{
    listnode *newlistnode = new listnode(data);
    newlistnode->next = head;

    head = newlistnode;
}

void insertAtTail(listnode *&tail, int data)
{
    listnode *newlistnode = new listnode(data);
    tail->next = newlistnode;
    tail = tail->next;
}
void printLinkedList(listnode *&head)
{
    listnode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


int getlen(listnode *head){
     int count = 0;
     
     listnode *temp = head;
     while(temp !=NULL){
         count ++;
         temp = temp->next;
     }
     return count;
 }
 
 
listnode* rotateRight(listnode* A, int B) {
    int l = 0;

    listnode *temp = A;
    while(temp->next !=NULL){
        l++;

        temp = temp->next;
    }
    l++;
    temp->next = A;

    B=B%l;
    int k=l-B;
    int i=1;
      temp=temp->next;
      while(i<k){i++;
          temp=temp->next;
      }
      listnode* head=temp->next;
      temp->next=NULL;

      return head;
    
}


int main()
{

    listnode *listnode1 = new listnode(5);
    listnode *head = listnode1;
    listnode *tail = listnode1;

    // insertAtHead(head,10);

    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    
    printLinkedList(head);
    head = rotateRight(head,3);
    printLinkedList(head);

    
    return 0;
}