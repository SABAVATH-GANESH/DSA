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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * temp=head;
        int total=0;
        while(temp!=NULL){
            total+=1;
            temp=temp->next;
        }
        if(total==n) return head->next;
        n=total-n;
        ListNode * temp1=head;
        while(n>1){
           temp1=temp1->next;
           n--;
          
        }
         temp1->next=temp1->next->next;
        return head;
        
    }
};