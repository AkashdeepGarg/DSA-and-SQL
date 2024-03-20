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
    int length(ListNode* head){
        ListNode* temp = head;
        int n=0;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        return n;
    }
    int getDecimalValue(ListNode* head) {
        int len = length(head);
        int ans=0;
        ListNode* temp = head;
        while(temp){
            if(temp->val==1)
            ans+=pow(2,len-1);
            len--;
            temp=temp->next;
        }
        return ans;
    }
};