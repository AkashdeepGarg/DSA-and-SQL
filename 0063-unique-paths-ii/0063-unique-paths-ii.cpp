class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid){
        if(m>=0 && n>=0 && obstacleGrid[m][n]==1){
            return dp[m][n]=0;
        }
        if(n==0 && m==0){
            return dp[m][n]=1;
        }
        if(n<0 || m<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int left = solve(m-1,n,dp,obstacleGrid);
        int right = solve(m,n-1,dp,obstacleGrid);

        return dp[m][n]=left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        solve(m-1,n-1,dp,obstacleGrid);

        return dp[m-1][n-1];
    }
};