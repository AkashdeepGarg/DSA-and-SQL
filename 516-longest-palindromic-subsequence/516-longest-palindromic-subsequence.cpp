class Solution {
public:
    int lcs(string S1, string S2, int n, int m){
        int t[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0)
                    t[i][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(S1[i-1]==S2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[n][m];
    }
    
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        int n = s.length();
        return lcs(s,r,n,n);
    }
};