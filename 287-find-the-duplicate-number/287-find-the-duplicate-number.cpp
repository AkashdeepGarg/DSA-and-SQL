class Solution {
public:
    // TC > O(N)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if((nums[i] xor nums[j])==0)
    //                 return nums[i];
    //         }
    //     }
    //     return 0;
    // }
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for (auto p : mp){
            if(p.second>1)
                return p.first;
        }
        return 0;
    }
};