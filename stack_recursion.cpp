class Solution {
private:
    void insert(stack<int>&st,int num){
        if(st.size() == 0){
            st.push(num);
            return;
        }
        int temp = st.top();
        st.pop();
        insert(st,num);
        st.push(temp);
    }
  public:
    void reverseStack(stack<int> &st) {
        // code here
        if(st.size() == 1)
            return;
        int t = st.top();
        st.pop();
        reverseStack(st);
        insert(st,t);
    }
};