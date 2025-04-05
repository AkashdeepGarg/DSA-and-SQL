class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp){
        if(n==0 && m==0){
            return 1;
        }
        if(n<0 || m<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int left = solve(m-1,n,dp);
        int right = solve(m,n-1,dp);

        return dp[m][n]=left+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        solve(m-1,n-1,dp);

        return dp[m-1][n-1];
    }
};