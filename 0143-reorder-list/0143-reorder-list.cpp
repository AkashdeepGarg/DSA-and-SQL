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
    ListNode* reverse(ListNode* root){
        if(!root or !root->next){
            return root;
        }
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (root != nullptr) {
            next = root->next;
            root->next = prev;
            prev = root;
            root = next;
        }
        return prev;
    }
    ListNode* middle;
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp = reverse(slow);
        
        ListNode* next;
        ListNode* prev;
        ListNode* firstHalf = head;
        ListNode* secondHalf = temp;
        while (secondHalf->next) {
            next = firstHalf->next;
            prev = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = next;
            
            firstHalf = next;
            secondHalf = prev;
        }
    }
};