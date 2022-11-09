class StockSpanner {
public:
    vector<int> v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        int res = 0;
        for (int i = (int) v.size() - 1; i >= 0; i--) {
            if (v[i] <= price) {
                res++;
            } else {
                break;
            }
        }
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */