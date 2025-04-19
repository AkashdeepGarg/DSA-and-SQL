class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }
        int i=0;int j=0;
        int n = nums.size();
        int sum=0;
        int ans=0;

        while(j<n){
            sum+=nums[j];
            if(sum > k){
                while(sum > k){
                    sum = sum-nums[i];
                    i++;
                }
            }
            ans = ans+(j-i+1);
            j++;
        }
        return ans;
    }


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal) - solve(nums,goal-1);
    }
};