class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int m = nums.size();
        int n = (1<<m);
        set<vector<int>> uniqueSubsets;
        for (int i = 0; i < n; i++) {
            vector<int> subset;
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    subset.push_back(nums[j]);
                }
            }
            uniqueSubsets.insert(subset);
        }
        return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
    }
};