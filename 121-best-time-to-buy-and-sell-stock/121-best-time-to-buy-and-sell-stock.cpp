class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int costprice=prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++){
            costprice=min(costprice,prices[i]);
            profit = max(profit,prices[i]-costprice);
        }
        return profit;
    }
};