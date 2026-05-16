class StockSpanner {
private:
    int day = 1;
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(st.size() && st.top().first <= price)
            st.pop();
        int span = day;
        if(st.size())
            span = day - st.top().second;
        st.push({price,day});
        day +=1;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */