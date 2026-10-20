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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode *temp=head;
        ListNode* prv=temp->next;
        
        temp->next=NULL;
        while(prv!=NULL){
            ListNode* cur=prv->next;
            prv->next=temp;
            temp=prv;
            prv=cur;
        }
        return temp;
    }
};