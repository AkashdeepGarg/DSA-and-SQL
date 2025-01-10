class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' and ans!=0){
                break;
            }else if(s[i]==' '){
                continue;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};