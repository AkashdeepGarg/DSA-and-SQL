class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp,up;
        for(int i=0;i<s.length();i++){
            if(up.count(s[i])==0 and mp.count(t[i])==0){
                mp[t[i]] = s[i];
                up[s[i]] = t[i];
            }
            else if(up.count(s[i])>0 and mp.count(t[i])>0){
                if(mp[t[i]] != s[i] or up[s[i]] != t[i]){
                    return false;
                }
            }
            else if(up.count(s[i])>0 or mp.count(t[i])>0){
                return false;
            }
        }
        return true;
    }
};