class Solution {
private:
    void insert(stack<int>&st,int t){
        if(st.size() == 0 || st.top() < t){
            st.push(t);
            return;
        }
        int temp = st.top();
        st.pop();
        insert(st,t);
        st.push(temp);
    }
  public:
    void sortStack(stack<int> &st) {
        // code here
        if(st.size() == 1)
            return;
        int t = st.top();
        st.pop();
        sortStack(st);
        insert(st,t);
    }
};
