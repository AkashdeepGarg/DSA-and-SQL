class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& dp){
        ans.push_back(dp);

        for(int i=ind;i<nums.size();i++){
            if(i!=ind and nums[i] == nums[i-1]) continue;

            dp.push_back(nums[i]);
            solve(i+1,nums,ans,dp);
            dp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> dp;
        sort(nums.begin(),nums.end());
        solve(0,nums,ans,dp);

        return ans;
    }
};