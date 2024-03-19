class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int r = mp[0];
        int w = mp[1];
        int b = mp[2];
        for(int i=0;i<nums.size();i++){
            if(r!=0){
                nums[i]=0;
                r--;
            }
            else if(w!=0){
                nums[i]=1;
                w--;
            }
            else{
                nums[i]=2;
            }
        }
    }
};