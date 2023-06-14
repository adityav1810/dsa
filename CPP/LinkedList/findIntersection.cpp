#include<iostream>
//  * Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode * solve(int d ,ListNode *h1,ListNode *h2){
    int pos = 0;
    ListNode *temp1 = h1;
    while (pos < d){
        pos ++;
        if(temp1 == NULL){
            return NULL;
        }
        temp1 = temp1->next;
    }
    
    ListNode *temp2 = h2;
    while(temp1 !=NULL && temp2 !=NULL ){
        if(temp1 == temp2){
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2 ->next;
        
    }
    return NULL;
}
 

int len (ListNode *h1){
    int count = 0;
    ListNode *temp = h1;
    while(temp !=NULL){
        count ++;
        temp = temp->next;
        
    }
    return count;
    
} 
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {

// check if any of the list are null
if(A == NULL || B== NULL){
    return NULL;
}

// find smaller list
int len1 = len(A);
int len2 = len(B);
ListNode *res = NULL;
if(len1>len2){
    res = solve(len1 - len2 ,A,B);
}
else{
    res = solve(len2 - len1 ,B,A);
}

return res;
}
