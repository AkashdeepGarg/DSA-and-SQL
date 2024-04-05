class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m=0;
        for(int num : nums){
            m = max(num, m);
        }
        int a[m+1],i,n=nums.size();
        for(int &t:a) t=0;
        for(int k : nums)a[k]+=k;
        
        int inc = a[0];
        int exc = 0;
        int ans;
        for(int i=1;i<=m;i++){
            ans = max(inc,exc);
            inc = exc + a[i];
            exc = ans;
        }
        return max(inc,exc);
    }
};