class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max = 0;
        int overmax = INT_MIN;
        for(int i=0;i<nums.size();i++){
            curr_max = max(curr_max+nums[i],nums[i]);
            overmax = max(overmax,curr_max);
        }
        
        return overmax;
    }
};