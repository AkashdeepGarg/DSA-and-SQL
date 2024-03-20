class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            temp1.push_back(sum);
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            temp2.push_back(sum);
        }
        for(int i=0;i<nums.size();i++){
            if(temp1[i]==temp2[nums.size()-i-1]){
                return i;
            }
        }
        return -1;
    }
};