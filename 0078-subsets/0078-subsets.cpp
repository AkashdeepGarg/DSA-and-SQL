class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int m = nums.size();
        int n = (1<<m);
        vector<vector<int>>ans(n);
        for(int i =0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i>>j) & 1) {
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};