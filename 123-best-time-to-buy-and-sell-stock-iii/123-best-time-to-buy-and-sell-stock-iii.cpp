class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n=price.size();
    int t[n];
    for(int i=0;i<n;i++){
        t[i]=0;
    }
    int ma=price[n-1];
    int mi=price[0];
    for(int i=n-2;i>=0;i--){
        ma=max(ma,price[i]);
        t[i] = max(t[i+1],ma-price[i]);
    }
    for(int i=1;i<n;i++){
        mi=min(mi,price[i]);
        t[i] = max(t[i-1],t[i]+(price[i]-mi));
    }
    return t[n-1];
    }
};