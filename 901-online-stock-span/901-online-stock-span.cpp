class StockSpanner {
public:
    stack<pair<int,int>> st;
    int cnt;
    StockSpanner() {
        cnt = 0;
    }
    
    int next(int price) {
        cnt++;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        if(st.empty()){
            st.push({price,cnt});
            return cnt;
        }
        int idx = st.top().second;
        st.push({price,cnt});
        return cnt-idx;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */