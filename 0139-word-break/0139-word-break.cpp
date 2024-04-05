class Solution {
public:
    // bool solve(string s, int i,int j, vector<string>& wordDict){
    //     string temp = s.substr(i,j-i+1);
    //     if(j==s.length()-1){
    //         for(auto t:wordDict){
    //             if(temp==t){
    //                 return true;
    //             }
    //         }
    //         return false;
    //     }
    //     for(auto t:wordDict){
    //         if(temp==t){
    //             if(solve(s,j+1,j+1,wordDict))
    //             return true;
    //         }
    //     }
    //     return solve(s,i,j+1,wordDict);
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     return solve(s,0,0,wordDict);
    // }
    
    
    bool solve(string s, int i,int j, vector<string>& wordDict, vector<vector<int>>& dp){
        if(dp[i][j]!=-1){
            return dp[i][j]==1 ? true : false;
        }
        string temp = s.substr(i,j-i+1);
        if(j==s.length()-1){
            for(auto t:wordDict){
                if(temp==t){
                    return true;
                }
            }
            return false;
        }
        for(auto t:wordDict){
            if(temp==t){
                if(solve(s,j+1,j+1,wordDict,dp)){
                    dp[i][j]=1;
                    return true;
                }
            }
        }
        dp[i][j] = solve(s,i,j+1,wordDict,dp) ? 1 : 0;
        return dp[i][j]==1 ? true : false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp( s.length() , vector<int> (s.length(),-1));
        return solve(s,0,0,wordDict,dp);
    }
};