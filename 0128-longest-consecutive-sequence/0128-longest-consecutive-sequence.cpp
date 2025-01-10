class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x: nums){
            mp[x]++;
        }
        int ans=0;
        for(auto m: mp){
            int temp = m.first;
            if(mp.find(temp-1)!=mp.end()){
                continue;
            }
            else{
                int count = 1;
                while(true){
                    if(mp.find(temp+1)!=mp.end()){
                        temp++;
                        count++;
                    }
                    else{
                        ans = max(ans,count);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};