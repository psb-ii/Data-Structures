class Solution {
private:
    vector<int> smallerToTheRight(vector<int>&arr){
        stack<pair<int,int>>st;
        vector<int>res;
        for(int i=arr.size()-1;i>=0;i=i-1){
            while(st.size() && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.size())
                res.push_back(st.top().second);
            else
                res.push_back(arr.size());
            st.push({arr[i],i});
        }
        reverse(res.begin(),res.end());
        return res;
    }
    vector<int> smallerToTheLeft(vector<int>&arr){
        stack<pair<int,int>>st;
        vector<int>res;
        for(int i=0;i<arr.size();i=i+1){
            while(st.size() && st.top().first > arr[i]){
                st.pop();
            }
            if(st.size())
                res.push_back(st.top().second);
            else
                res.push_back(-1);
            st.push({arr[i],i});
        }
        return res;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>s_left = smallerToTheLeft(arr);
        vector<int>s_right = smallerToTheRight(arr);
        long long int count = 0ll;
        const int MOD = 1e9 + 7;
        for(int i=0;i<arr.size();i=i+1){
            int left = i - s_left[i] - 1;
            int right = s_right[i] - i - 1;
            count = (1LL*count + 1LL*arr[i]*(left + right + 1 + 1LL*left*right)) % MOD; 
        }
        return count;
    }
};