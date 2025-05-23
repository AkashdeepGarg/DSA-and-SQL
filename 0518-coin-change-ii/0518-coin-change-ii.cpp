class Solution {
public:
    int solve(vector<int>& coins,int n,int amount,vector<vector<int>>& dp){
        if(n==0){
            return dp[n][amount] = 0;
        }
        if(amount==0){
            return dp[n][amount]=1;
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }
        if(coins[n-1]<=amount){
            return dp[n][amount] = solve(coins,n,amount-coins[n-1],dp) + solve(coins,n-1,amount,dp);
        }
        else{
            return dp[n][amount] = solve(coins,n-1,amount,dp);
        }
        return dp[n][amount];
    }


    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        
        return solve(coins,n,amount,dp);
    }
};