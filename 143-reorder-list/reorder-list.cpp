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
    void reorderList(ListNode* head) {
        unordered_map<int,ListNode*>mp;
        int i=0;
        ListNode * temp=head;
        while(temp!=NULL){
           mp[i]=temp;
           temp=temp->next;
           i++;
        }
        int n=mp.size();
        ListNode* temp1=head;
        int j=n-1;
        int k=1;
        int l=0;
        while(k<=j){
            if(l==0){
                temp1->next=mp[j];
                temp1=mp[j];
                j-=1;
                l=1;
            }else{
                temp1->next=mp[k];
                temp1=mp[k];
                k +=1;
                l=0;
            }
        }
        temp1->next=NULL;
        
        
    }
};