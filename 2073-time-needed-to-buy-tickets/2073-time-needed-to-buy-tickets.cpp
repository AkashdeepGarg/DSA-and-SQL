class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<tickets.size();i++){
            q.push({tickets[i],i});
        }
        while(q.size()!=0){
            int temp = q.front().first;
            int index = q.front().second;
            if(temp!=0){
                temp = temp-1;
                count++;
            }
            if(temp==0 and index==k){
                return count;
            }
            q.pop();
            q.push({temp,index});
        }
        
        return count;
    }
};