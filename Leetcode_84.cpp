class Solution {
    private:
        vector<int> smallerToTheLeft(vector<int>&arr){
            vector<int>res;
            stack<pair<int,int>>st;
            for(int i=0;i<arr.size();i=i+1){
                while(st.size() && st.top().first >= arr[i])
                    st.pop();
                if(st.size())
                    res.push_back(st.top().second);
                else
                    res.push_back(-1);
                st.push({arr[i],i});
            }
            return res;
        }
        vector<int> smallerToTheRight(vector<int>&arr){
            vector<int>res;
            stack<pair<int,int>>st;
            for(int i=arr.size()-1;i>=0;i=i-1){
                while(st.size() && st.top().first >= arr[i])
                    st.pop();
                if(st.size())
                    res.push_back(st.top().second);
                else
                    res.push_back(arr.size());
                st.push({arr[i],i});
            }
            reverse(res.begin(),res.end());
            return res;
        }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> s_left = smallerToTheLeft(heights);
        vector<int> s_right = smallerToTheRight(heights);
        int res = 0;
        for(int i=0;i<heights.size();i=i+1){
            int left = i - s_left[i] - 1;
            int right = s_right[i] - i - 1;
            int curr_max = (left+right+1)*heights[i];
            res = max(res,curr_max);
        }
        return res;
    }
};