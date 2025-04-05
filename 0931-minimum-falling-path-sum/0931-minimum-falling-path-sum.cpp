class Solution {
public:
    // int solve(int m,int n,vector<vector<int>>& dp,vector<vector<int>>& matrix){
    //     if(m<0 || n<0 || n>matrix.size()-1){
    //         return 1e9;
    //     }
    //     if(m==0){
    //         return dp[0][n]=matrix[0][n];
    //     }

    //     if(dp[m][n]!=-1){
    //         return dp[m][n];
    //     }

    //     int diagonal = matrix[m][n] + solve(m-1,n+1,dp,matrix);
    //     int top = matrix[m][n] + solve(m-1,n,dp,matrix);
    //     int left = matrix[m][n] + solve(m-1,n-1,dp,matrix);

    //     return dp[m][n] = min({diagonal,top,left});
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        //For memoization
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // int mini = INT_MAX;
        // for(int j=0;j<n;j++){
        //     mini = min(mini, solve(m-1,j,dp,matrix));
        // }

        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int up = matrix[i][j] + dp[i - 1][j];

                int leftDiag = matrix[i][j] + (j > 0 ? dp[i - 1][j - 1] : 1e9);
                int rightDiag = matrix[i][j] + (j < n - 1 ? dp[i - 1][j + 1] : 1e9);

                dp[i][j] = min({up, leftDiag, rightDiag});

            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[m - 1][j]);
        }
        

        return mini;
    }
};