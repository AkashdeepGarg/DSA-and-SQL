/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* temp){
        ListNode* t = temp;
        int i=0;
        while(t){
            i++;
            t=t->next;
        }
        return i;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = length(headA);
        int b = length(headB);
        if(a>b){
            while(a!=b){
                headA = headA->next;
                a--;
            }
        }
        else if(a<b){
            while(a!=b){
                headB = headB->next;
                b--;
            }
        }
        while(headA and headB){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};