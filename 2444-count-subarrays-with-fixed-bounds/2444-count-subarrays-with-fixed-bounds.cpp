class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mini=-1,maxi=-1,culprit=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxK or nums[i]<minK){
                culprit = i;
            }
            if(nums[i]==maxK){
                maxi=i;
            }
            if(nums[i]==minK){
                mini=i;
            }
            int temp = min(maxi,mini);
            temp = temp-culprit;
            if(temp>0)
            ans += (temp);
        }
        return ans;
    }
};