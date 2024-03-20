class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==0){
            return ans;
        }
        int i=0;
        int n=nums.size()-1;
        while(n>=i){
            if(abs(nums[i]) > abs(nums[n])){
                ans.push_back(pow(nums[i],2));
                i++;
            }
            else if(abs(nums[i]) <= abs(nums[n])){
                ans.push_back(pow(nums[n],2));
                n--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};