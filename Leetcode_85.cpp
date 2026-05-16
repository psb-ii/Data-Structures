class Solution {
private:
    vector<int> getSmallerToLeft(vector<int>&arr){
        vector<int>smaller;
        stack<pair<int,int>>st;
        for(int i=0;i<arr.size();i=i+1){
            while(st.size() && st.top().first >= arr[i])
                st.pop();
            if(st.size())
                smaller.push_back(st.top().second);
            else
                smaller.push_back(-1);
            st.push({arr[i],i});
        }
        return smaller;
    }
    vector<int> getSmallerToRight(vector<int>&arr){
        vector<int>smaller;
        stack<pair<int,int>>st;
        for(int i=arr.size()-1;i>=0;i=i-1){
            while(st.size() && st.top().first >= arr[i])
                st.pop();
            if(st.size())
                smaller.push_back(st.top().second);
            else
                smaller.push_back(arr.size());
            st.push({arr[i],i});
        }
        reverse(smaller.begin(),smaller.end());
        return smaller;
    }
    int getMaximumRectangleArea(vector<int>&arr){
        vector<int>s_left = getSmallerToLeft(arr);
        vector<int>s_right = getSmallerToRight(arr);
        int area = 0;
        for(int i=0;i<arr.size();i=i+1){
            area = max(area,arr[i]*(s_right[i]-s_left[i]-1));
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>curr(matrix[0].size(),0);
        int res = 0;
        for(int i=0;i<matrix.size();i=i+1){
            for(int j=0;j<matrix[i].size();j=j+1){
                curr[j] += matrix[i][j] == '1' ? 1 : -1*curr[j];
            }
            int maxRect = getMaximumRectangleArea(curr);
            res = max(res,maxRect);
        }
        return res;
    }
};