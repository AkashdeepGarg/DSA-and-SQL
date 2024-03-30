class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i=0,j=0,ans=0;
        int n=s.length();
        while(j<n){
            mp[s[j]]++;
            while(i<=j and mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};