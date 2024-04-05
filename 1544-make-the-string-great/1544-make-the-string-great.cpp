class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        int i=0;
        while(i<n-1){
            if((toupper(s[i])==s[i+1] || toupper(s[i+1])==s[i]) and s[i]!=s[i+1]){
                s.erase(i,2);
                i=0;
            }
            else{
                i++;
            }
        }
        return s;
    }
};