class Solution {
public:
    int solve(int n,vector<int> &nums, vector<int> &dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return dp[n]=nums[0];
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        int pick = nums[n]+solve(n-2,nums,dp);
        int notPick = solve(n-1,nums,dp);

        return dp[n] = max(pick,notPick);
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        vector<int> first;
        vector<int> second;

        for(int i = 0; i < n - 1; i++) {
            first.push_back(nums[i]);
        }

        for(int i = 1; i < n; i++) {
            second.push_back(nums[i]);
        }

        solve(n-2,first,dp1);
        solve(n-2,second,dp2);

        return max(dp1[n-2],dp2[n-2]);
    }
};