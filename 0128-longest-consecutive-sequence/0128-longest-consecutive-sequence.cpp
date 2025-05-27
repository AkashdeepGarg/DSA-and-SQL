class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]=1;
        }

        int maxLen=0;

        for(auto n1 : mp){
            int num = n1.first;
            if (mp.find(num - 1) == mp.end()) {
                int currentNum = num;
                int count = 1;

                while (mp.find(currentNum + 1) != mp.end()) {
                    currentNum++;
                    count++;
                }

                maxLen = max(maxLen, count);
            }
        }
        return maxLen;
    }
};