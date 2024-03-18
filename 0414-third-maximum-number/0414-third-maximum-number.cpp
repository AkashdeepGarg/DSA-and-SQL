class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int,int> mp;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==0){
                pq.push(nums[i]);
                mp[nums[i]]=1;
            }
            if(pq.size()>3){
                pq.pop();
            }
        }
        if(pq.size()<3){
            while(pq.size()>1){
                pq.pop();
            }
        }
        return pq.top();
    }
};