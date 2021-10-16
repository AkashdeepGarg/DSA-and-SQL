class Solution {
public:
    int length(ListNode *head){
        ListNode* temp=head;
        if(head==NULL){
            return 0;
        }
        int count=1;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=length(headA);
        int b=length(headB);
        int d;
        if(a>b){
            d=a-b;
            ListNode* first=headA;
            ListNode* second=headB;
            while(d){
                d--;
                first=first->next;
            }
            while(first!=NULL && second!=NULL){
                if(first==second){
                    return first;
                }
                first=first->next;
                second=second->next;
            }
            
        }
        else{
            d=b-a;
            ListNode* first=headB;
            ListNode* second=headA;
            while(d){
                d--;
                first=first->next;
            }
            while(first!=NULL && second!=NULL){
                if(first==second){
                    return first;
                }
                first=first->next;
                second=second->next;
            }
        }
        return NULL;
    }
};
