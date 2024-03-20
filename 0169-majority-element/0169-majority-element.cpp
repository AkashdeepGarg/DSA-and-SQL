class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans = INT_MIN;
        int a;
        for(auto x: mp){
            if(ans<x.second){
                ans = max(ans,x.second);
                a = x.first;
            }
        }
        return a;
    }
};