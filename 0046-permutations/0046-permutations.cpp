class Solution {
public:
    void solve(vector<int> &ds, vector<int>& nums, vector<vector<int>>& ans, unordered_map<int,int>& mp){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==0){
                mp[nums[i]]=1;
                ds.push_back(nums[i]);
                solve(ds,nums,ans,mp);
                mp[nums[i]]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]=0;
        }

        solve(ds,nums,ans,mp);

        return ans;
    }
};