class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            int j = i+1, k = nums.size()-1;
            int temp = nums[i];
            while(j<k){
                int sum = nums[j] + nums[k] + temp;
                if(sum==0){
                    result.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        
        vector<vector<int>> ans;
        for(auto s: result){
            ans.push_back(s);
        }

        return ans;
    }
};