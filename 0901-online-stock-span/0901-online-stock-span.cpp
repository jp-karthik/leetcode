class StockSpanner {
public:
    stack<pair<int,int>> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int f = 1;
        while (st.size() && st.top().first <= price) {
            f += st.top().second;
            st.pop();
        }
        st.push({price, f});
        return f;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */