class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        stack <int> s;
        if(head!=NULL){

            while(slow != NULL){
                    s.push(slow->val);

                    // Move ahead
                    slow = slow->next;
            }
            slow=head;
            while(slow!=NULL){
                int i=s.top();
                s.pop();
                if(slow->val!=i){
                    return 0;
                }
                slow=slow->next;
            }
        }
        
        return 1;
    }
};
