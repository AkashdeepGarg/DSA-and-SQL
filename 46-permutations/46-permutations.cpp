class Solution {
public:
    void recursion( int idx, vector<vector<int>>& ans , vector<int>& nums)
    {
        if( idx == nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        
        for( int i =idx;i< nums.size();i++)
        {
            swap( nums[idx], nums[i]);
            recursion( idx+1, ans, nums );
            swap( nums[idx], nums[i]);
        }
         
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recursion( 0, ans, nums);
        return ans ;
        
    }
};