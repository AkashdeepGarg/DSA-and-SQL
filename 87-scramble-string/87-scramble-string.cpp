class Solution {
public:
    //RECURSIVE APPROACH
    // bool isScramble(string s1, string s2) {
    //     if(s1.length()!=s2.length())
    //         return false;
    //     if(s1.compare(s2)==0)
    //         return true;
    //     if(s1.length()<=1)
    //         return false;
    //     int n = s1.length();
    //     bool ans = false;
    //     for(int i=1;i<=n-1;i++){
    //         if((isScramble(s1.substr(0,i),s2.substr(n-i,i))) && (isScramble(s1.substr(i,n-i),s2.substr(0,n-i))) == true || (isScramble(s1.substr(0,i),s2.substr(0,i))) && (isScramble(s1.substr(i,n-i),s2.substr(i,n-i))) == true){
    //             ans=true;
    //             break;
    //         }
    //     }
    //     return ans;
    // }
    
    //DP APPROACH
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())
            return false;
        if(s1.compare(s2)==0)
            return true;
        if(s1.length()<=1)
            return false;
        string key = s1;
        key.push_back(' ');
        key.append(s2);
        if(mp.find(key)!=mp.end())
            return mp[key];
        int n = s1.length();
        bool ans = false;
        for(int i=1;i<=n-1;i++){
            if((isScramble(s1.substr(0,i),s2.substr(n-i,i))) && (isScramble(s1.substr(i,n-i),s2.substr(0,n-i))) == true || (isScramble(s1.substr(0,i),s2.substr(0,i))) && (isScramble(s1.substr(i,n-i),s2.substr(i,n-i))) == true){
                ans=true;
                break;
            }
        }
        return mp[key]=ans;
    }
};