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
    ListNode* rotateRight(ListNode* head, int k) {
        //Correct but TLE exceeding

        // if(!head or k==0){
        //     return head;
        // }
        // ListNode* temp = head;
        // while(temp and temp->next){
        //     if(!temp->next->next){
        //         ListNode* newHead = temp->next;
        //         temp->next = NULL;
        //         newHead->next = head;
        //         head = newHead;
        //         break;
        //     }
        //     else{
        //         temp = temp->next;
        //     }
        // }
        // return (rotateRight(head,k-1));
        if(!head or k==0){
            return head;
        }
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        if(len==1){
            return head;
        }
        int t;
        if(k>=len){
            t = k%len;
        }
        else{
            t = k;
        }
        if(t==0){
            return head;
        }
        t = len-t+1;
        int i = 1;
        temp = head;
        while(i<t-1){
            temp = temp->next;
            i++;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        temp = newHead;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;

        return newHead;
    }
};