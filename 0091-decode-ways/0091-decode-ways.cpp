class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        int n=s.length();
        int dp[n+1];
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(s[i-1]=='0' and s[i]=='0'){
                return 0;
            }
            else if(s[i-1]=='0' and s[i]!='0'){
                dp[i] = dp[i-1];
            }
            else if(s[i-1]!='0' and s[i]=='0'){
                if(s[i-1]>'2'){
                    return 0;
                }
                else{
                    if(i-2<0){
                        dp[i]=dp[i-1];
                    }
                    else{
                        dp[i] = dp[i-2];
                    }
                }
            }
            else{
                int x = s[i-1]-'0';
                x = x*10 + s[i]-'0';
                if(x>=1 and x<=26){
                    if(i-2<0){
                        dp[i]=dp[i-1]+1;
                    }
                    else{
                        dp[i] = dp[i-2]+dp[i-1];
                    }
                }
                else{
                    dp[i] = dp[i-1];
                }
            }
        }
        
        return dp[n-1];
    }
};