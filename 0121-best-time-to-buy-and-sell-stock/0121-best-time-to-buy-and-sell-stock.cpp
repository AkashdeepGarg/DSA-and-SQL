class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.size()<2){
            return 0;
        }
        int i=0,j=1;
        while(i<j and j<prices.size()){
            int temp = prices[j]-prices[i];
            if(temp<0){
                i=j;
                j++;
            }
            else{
                j++;
                ans = max(ans,temp);
            }
        }

        return ans;
    }
};