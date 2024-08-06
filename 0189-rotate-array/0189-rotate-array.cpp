class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // if(nums.size()<2){
        //     return;
        // }
        // int i=0;
        // int j=nums.size()-k-1;
        // while(i<j){
        //     swap(nums[i],nums[j]);
        //     i++;
        //     j--;
        // }
        // i = nums.size()-k;
        // j=nums.size()-1;
        // while(i<j){
        //     swap(nums[i],nums[j]);
        //     i++;
        //     j--;
        // }
        // reverse(nums.begin(),nums.end());
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};