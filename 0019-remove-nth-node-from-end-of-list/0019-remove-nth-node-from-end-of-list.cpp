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
        if(!head){
            return head;
        }
        if(!head->next){
            return NULL;
        }
        ListNode* temp = head;
        int len = lengthOfList(head);
        int N = len - n;
        if(N==0){
            head=head->next;
            return head;
        }
        cout<<N;
        
        while(1){
            if(N==1){
                break;
            }
            temp = temp->next;
            N--;
        }
        
        temp->next = temp->next->next;
        
        return head;
    }
    
    int lengthOfList(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        
        return len;
    }
};