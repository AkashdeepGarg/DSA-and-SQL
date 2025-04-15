class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int n=s.length();
        int i=0,j=0;
        int maxi=0;
        int maxf=0;

        while(j<n){
            mp[s[j]]++;
            maxf = max(maxf,mp[s[j]]);
            while(j-i+1 - maxf > k){
                mp[s[i]]--;
                i++;
                for(auto m:mp){
                    maxf = max(maxf,m.second);
                }
            }

            maxi = max(maxi, j - i + 1);
            j++;
        }

        return maxi;
    }
};