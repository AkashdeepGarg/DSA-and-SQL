class Solution {
public:
    bool solve(int ind,int target, vector<int>&arr, vector<vector<int>>&dp){
        if(target==0){
            return dp[ind][target]=true;
        }
        if (ind == 0)
            return arr[0] == target;

        if (dp[ind][target] != -1)
        return dp[ind][target];

        bool notTaken = solve(ind-1,target,arr,dp);
        bool taken = false;
        if(target>=arr[ind]){
            taken = solve(ind-1,target-arr[ind],arr,dp);
        }

        return dp[ind][target] = taken || notTaken;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i:nums){
            totalSum+=i;
        }

        vector<vector<int>> dp(n,vector<int>(totalSum+1,-1));

        

        if(totalSum%2!=0){
            return false;
        }
        else{
            return solve(n-1,totalSum/2,nums,dp);
        }
    }
};