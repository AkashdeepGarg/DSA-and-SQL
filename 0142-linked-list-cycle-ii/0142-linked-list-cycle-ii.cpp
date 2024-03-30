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
    ListNode *detectCycle(ListNode *head) {
         if(head==NULL || head->next == NULL)
            return NULL;
			
        ListNode* fastPtr = head, *slowPtr = head;
        
        while(fastPtr != NULL && fastPtr->next != NULL)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            
            if(fastPtr == slowPtr)
                break;
        }
        
        if(fastPtr == NULL || fastPtr->next == NULL) 
            return NULL;
        
        while(head != slowPtr)
        {
            head = head->next;
            slowPtr = slowPtr->next;
        }
        return head;
    }
};