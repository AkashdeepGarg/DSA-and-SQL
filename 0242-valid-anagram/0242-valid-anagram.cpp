class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int n = t.length();
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        for(char c:t){
            if(mp[c]<1){
                return false;
            }
            mp[c]--;
        }
        return true;
    }
};