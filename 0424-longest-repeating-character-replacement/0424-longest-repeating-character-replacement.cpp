class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,maxf=0,ans=0;
        unordered_map<char,int> mp;
        int n=s.length();
        while(j<n){
            mp[s[j]]++;
            maxf = max(maxf,mp[s[j]]);
            while(j-i+1-maxf > k){
                mp[s[i]]--;
                i++;
                for(auto x:mp){
                    maxf = max(maxf,x.second);
                }
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};