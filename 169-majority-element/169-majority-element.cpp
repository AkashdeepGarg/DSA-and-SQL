class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> ma;
        int n = nums.size();
        int m = int(n/2);
        for(int k :nums){
            ma[k]++;
        }
        for(int i =0; i<n; i++){
            if(ma[nums[i]] > m){
                return nums[i];
            }
        }
        return 0;
    }
};