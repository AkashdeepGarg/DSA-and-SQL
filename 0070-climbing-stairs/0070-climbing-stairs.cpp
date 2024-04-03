class Solution {
public:
    
    //Memoization
    // int climbStairs(int n, vector<int> & t){
    //     if(n<0){
    //         return 0;
    //     }
    //     if(n==0){
    //         return 1;
    //     }
    //     if(t[n]!=-1){
    //         return t[n];
    //     }
    //     return t[n] = climbStairs(n-1)+climbStairs(n-2);
    // }
    int climbStairs(int n) {
        //Recursion
        // if(n<0){
        //     return 0;
        // }
        // if(n==0){
        //     return 1;
        // }
        // return climbStairs(n-1)+climbStairs(n-2);
        
        //Momoization and DP(Bottom UP approach)
        
        vector<int> t(46);
        t[0] = 1;
        t[1] = 1;
        for(int i=2;i<=n;i++){
            t[i] = t[i-1]+t[i-2];
        }
        return t[n];
        // return climbStairs(n,t);
    }
};