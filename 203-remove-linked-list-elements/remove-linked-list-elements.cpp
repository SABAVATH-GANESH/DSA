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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        ListNode* temp=head;
        ListNode* prv=NULL;
        while(temp!=NULL){
            if(temp->val==val){
                if(prv==NULL){
                    head=head->next;
                    temp=head;
                }else{
                    prv->next=temp->next;
                    temp=temp->next;
                }
            }else{
                prv=temp;
                temp=temp->next;
            }
        }
        return head;
        
    }
};