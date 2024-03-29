class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=0){
            return 0;
        }
        int n=nums.size();
        int ans=1;
        int result=0;
        int i=0,j=0;
        while(j<n){
            ans = ans*nums[j];
            while(i<=j and ans >= k){
                ans = ans / nums[i];
                i++;
            }
            result = result + j-i+1;
            j++;
        }
        
        
        return result;
    }
};