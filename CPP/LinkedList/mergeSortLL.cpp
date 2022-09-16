/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    ListNode* merge(ListNode *left,ListNode *right){
//         check if either list in NULL, return other list
        if(left ==NULL){
            return right;
        }
        if(right ==NULL){
            return left;
        }
//         create dummy node for sorted list
        ListNode *res = new ListNode(-1);
        ListNode *temp = res;
        while(left!=NULL && right !=NULL){
//     if left->data < right->data ; add on the left node in result LL
            if(left->val < right->val){
                temp->next = left;
                temp = left;
                left = left->next;
                
                }else{
                temp->next = right;
                temp= right;
                right = right->next;
                
            }
        }
//         add remaining lists to ans
        while(left !=NULL){
            temp ->next = left;
            temp = left;
            left = left->next;
        }
        while(right !=NULL){
            temp ->next = right;
            temp = right;
            right = right->next;
        }
        
        return res->next;
        
    }
    
    ListNode* findMid(ListNode * head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast!=NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
        
    }
    
public:
    ListNode* sortList(ListNode* head) {
//         if list len is 0 or 1 
        if(head == NULL || head->next == NULL){
            return head;
        }
//          find middle of list and break into 2 parts
        ListNode *mid= findMid(head);
        
        ListNode *left = head;
        ListNode *right = mid->next;
        mid ->next = NULL;
//         sort each part individually
        left = sortList(left);
        right = sortList(right);
//         merge sorted lists into single list
        ListNode *result = merge(left,right);
//         return head of sorted list
        return result;
    }
};