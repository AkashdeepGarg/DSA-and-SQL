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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(!list2){
            return list1;
        }
        b++;
        ListNode* temp1 = list1;
        ListNode* temp2 = list1;
        ListNode* temp = list1;
        while((a>=0 or b>=0) and temp!=NULL){
            a--;
            b--;
            if(a==0){
                temp1 = temp;
                cout<<temp->val;
            }
            if(b==0){
                temp2 = temp;
                cout<<temp2->val;
            }
            temp = temp->next;
        }
        temp1->next = list2;
        temp2 = temp2->next;
        temp = list2;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = temp2;
        
        return list1;
    }
};