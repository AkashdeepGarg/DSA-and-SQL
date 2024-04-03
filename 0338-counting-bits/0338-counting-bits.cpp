class Solution {
public:
    vector<int> countBits(int n) {
        //Bitmanipulation (BUT tuntime error for large inputs)
        // vector<int> ans;
        // for(int i=0;i<=n;i++){
        //     int count = 0;
        //     for(int j=0;j<=n;j++){
        //         if((i&(1<<j))!=0){
        //             count++;
        //         }
        //     }
        //     ans.push_back(count);
        // }
        // return ans;
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                ans[i] = ans[i/2];
            }
            else{
                ans[i] = ans[i/2] + 1;
            }
        }
        
        return ans;
        
    }
};