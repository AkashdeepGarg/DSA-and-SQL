class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int j;
        for(int i=nums.size()-1;i>=index;i--){
            if(nums[index]<nums[i]){
                j=i;
                break;
            }
        }
        swap(nums[index],nums[j]);
        reverse(nums.begin()+index+1,nums.end());
    }
};