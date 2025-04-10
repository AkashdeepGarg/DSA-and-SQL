class Solution {
public:
    void solve(vector<int>& nums, unordered_map<int,int>& mp, vector<int>& temp, vector<vector<int>>& ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(auto i: mp){
            if(i.second>0){
                temp.push_back(i.first);
                mp[i.first]--;
                solve(nums,mp,temp,ans);
                temp.pop_back();
                mp[i.first]++;
            }
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<int> temp;
        solve(nums,mp,temp,ans);

        return ans;
    }
};