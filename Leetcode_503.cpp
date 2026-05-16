class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>temp = nums;
        stack<int>st;
        for(int i=0;i<nums.size();i=i+1){
            temp.push_back(nums[i]);
        }
        vector<int>res;
        for(int i = temp.size() - 1;i >= 0;i = i - 1){
            while(st.size() && st.top() <= temp[i])
                st.pop();
            if(st.size())
                res.push_back(st.top());
            else
                res.push_back(-1);
            st.push(temp[i]);
        }
        vector<int>g;
        for(int i = 0;i < nums.size();i = i + 1)
            g.push_back(res[res.size()-1-i]);
        return g;
    }
};