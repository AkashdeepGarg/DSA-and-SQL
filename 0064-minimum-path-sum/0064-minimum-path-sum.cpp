class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(m==0 && n==0){
            return dp[m][n]=grid[m][n];
        }
        if(m<0 || n<0){
            return 1e9;
        }

        if(dp[m][n]!=-1){
            return dp[m][n];
        }

        int top = grid[m][n] + solve(m-1,n,grid,dp);
        int left = grid[m][n] + solve(m,n-1,grid,dp);

        return dp[m][n] = min(top,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        solve(m-1,n-1,grid,dp);

        return dp[m-1][n-1];
    }
};