class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int h=n-1;

        while(l<=h){
            int mid = l+ (h-l)/2;
            bool leftOk = mid==0 || nums[mid-1] < nums[mid];
            bool rightOk = mid==n-1 || nums[mid+1] < nums[mid];

            if(leftOk && rightOk){
                return mid;
            }

            if(mid > 0 && nums[mid-1] > nums[mid]){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return -1;
    }
};