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
        int n = nums.size();
        int sm=0;
        for(auto x : nums)  sm+=x;
        if(sm<target || (sm-target)%2!=0)
            return 0;
        int sm2 = (sm-target)/2;
        vector<vector<int>> t(n+1,vector<int>(sm2+1,0));
        t[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sm2;j++)
            {
                if(nums[i-1]<=j)
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sm2];
        
    }
};