class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        vector<int>res;
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i=i-1){
            while(st.size() && st.top() >= arr[i])
                st.pop();
            if(st.size() > 0){
                res.push_back(st.top());
            }
            else
                res.push_back(-1);
            st.push(arr[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};