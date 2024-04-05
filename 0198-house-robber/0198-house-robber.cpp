class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int inc = nums[0];
        int exc = 0;
        int ans;
        for(int i=1;i<n;i++){
            ans = max(inc,exc);
            inc = exc + nums[i];
            exc = ans;
        }
        return max(inc,exc);
    }
};