class Solution {
public:
    int binarySearch(vector<int> nums, int l, int r, int x){
        while(l<=r){
            int m = l + ((r-l)/2);
            if(nums[m]==x){
                return m;
            }
            if(nums[m]>x){
                r = m-1;
            }
            else if(nums[m]<x){
                l = m+1;
            }
        }
        return -1;
        
    }
    
    int search(vector<int>& nums, int target) {
        
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};