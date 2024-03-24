class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // TC O(n^2)
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if((nums[i] xor nums[j])==0)
        //             return nums[i];
        //     }
        // }
        // return 0;
        
        //TC O(N), SC O(N)
        // map<int,int> mp;
        // for(int i=0;i<nums.size();i++){
        //     if(mp[nums[i]]>0){
        //         return nums[i];
        //     }
        //     mp[nums[i]]++;
        // }
        // return nums[0];
        
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
        
    }
};