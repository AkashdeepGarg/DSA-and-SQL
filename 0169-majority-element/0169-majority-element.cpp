class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==num){
                count++;
            }
            else{
                    count--;
                    if(count==0){
                        num=nums[i];
                        count=1;
                    }
            }
        }
        int freq=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num){
                freq++;
            }
        }
        if(freq>nums.size()/2){
            return num;
        }
        
        return -1;
    }
};