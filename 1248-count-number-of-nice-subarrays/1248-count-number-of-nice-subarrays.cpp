class Solution {
private:
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
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }

        return solve(nums,k) - solve(nums,k-1);
    }
};