class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1){
            return 0;
        }
            int i=0;
        int j=1;
        int maxProfit = 0;
        int profit=0;
        while(j<prices.size()){
            profit = prices[j]-prices[i];
            if(profit<0){
                i=j;
                j++;
                profit=0;
            }
            else{
                j++;
            }
            maxProfit = max(profit,maxProfit);
        }
        return maxProfit;
    }
};