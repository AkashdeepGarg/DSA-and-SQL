class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxe = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxe = max(maxe,nums[i]);
        }
        long long ans=0;
        map<int,int> mp;
        int i=0,j=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp[maxe] >=k){
                ans= ans+n-j;
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};