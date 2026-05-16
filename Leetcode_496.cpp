class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>ma;
        stack<int>st;
        for(int i = nums2.size() - 1;i >= 0;i = i - 1){
            while(st.size() && nums2[i] >= st.top()){
                st.pop();
            }
            if(st.size())
                ma[nums2[i]] = st.top();
            else
                ma[nums2[i]] = -1;
            st.push(nums2[i]);
        }
        vector<int>res;
        for(int i = 0;i < nums1.size();i = i + 1){
            res.push_back(ma[nums1[i]]);
        }
        return res;
    }
};