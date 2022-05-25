class Solution {
public:
    // int noofsubset(vector<int>& arr, int sum){
    //     int n = arr.size();
    //     int t[n+1][sum+1];
    //     for(int i=0;i<n+1;i++){
    //         for(int j=0;j<sum+1;j++){
    //             if(i==0)
    //             t[i][j]=0;
    //             if(j==0)
    //             t[i][j]=1;
    //         }
    //     }
    //     for(int i=1;i<n+1;i++){
    //         for(int j=1;j<sum+1;j++){
    //             if(arr[i-1]<=j){
    //                 t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
    //             }
    //             else{
    //                 t[i][j] = t[i-1][j];
    //             }
    //         }
    //     }
    //     return t[n][sum];
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int sum=0,count=0;
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         sum+=nums[i];
    //         if(nums[i]==0)
    //             count++;
    //     }
    //     sum = sum-target;
    //     if(sum%2!=0){
    //         return 0;
    //     }
    //     else{
    //         sum = sum/(int)2;
    //         return noofsubset(nums,sum)+count;
    //     }
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        if(sum<target || ((sum+target)/2)<0 || (sum+target)%2!=0)
            return 0;
        
        sum+=target;
        sum=sum/2;
        int dp[n+1][sum+1];
        
        dp[0][0]=1;
        
        for(int i=1;i<=sum;i++)
            dp[0][i]=0;
        
        for(int i=1;i<=n;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};