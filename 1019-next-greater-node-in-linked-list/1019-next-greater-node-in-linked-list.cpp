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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n = v.size();
        vector<int> ans;
        stack<int> S;
        for(int i=n-1;i>=0;i--){
            if(S.size()==0){
                ans.push_back(0);
            }
            else if(S.size()>0 && S.top()>v[i]){
                ans.push_back(S.top());
            }
            else if(S.size()>0 && S.top()<=v[i]){
                while(S.size()>0 && S.top()<=v[i]){
                    S.pop();
                }
                if(S.size()==0){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(S.top());
                }
            }
            
            S.push(v[i]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};