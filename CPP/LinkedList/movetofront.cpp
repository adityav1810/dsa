//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    ListNode *moveToFront(ListNode *&head){
        ListNode *prev = NULL;
      ListNode *curr = head;
        while(curr !=NULL){
          prev = curr;
            curr = curr->next;
        }
        cout<<curr->val;
    prev->next = NULL;
    curr->next = head;
    head = curr;
    
    return head;
        
    }
};
int main(){
    ListNode *head = new ListNode (4);
    head->next = new ListNode (3);
    head->next->next = new ListNode (5);
    moveToFront(head);
    

    return 0;
}