class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = 0;
        for(int i=0;i<nums.size();i++){
            temp = temp xor nums[i];
        }
        return temp;
    }
};