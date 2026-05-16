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
    vector<int> greaterToTheRight(vector<int>&arr){
        stack<pair<int,int>>st;
        vector<int>res;
        for(int i=arr.size()-1;i>=0;i=i-1){
            while(st.size() && st.top().first <= arr[i]){
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
    vector<int> greaterToTheLeft(vector<int>&arr){
        stack<pair<int,int>>st;
        vector<int>res;
        for(int i=0;i<arr.size();i=i+1){
            while(st.size() && st.top().first < arr[i]){
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
    long long subArrayRanges(vector<int>& nums) {
        vector<int>s_left = smallerToTheLeft(nums);
        vector<int>s_right = smallerToTheRight(nums);
        vector<int>g_left = greaterToTheLeft(nums);
        vector<int>g_right = greaterToTheRight(nums);
        long long int count = 0;
        for(int i=0;i<nums.size();i=i+1){
            int s_left_size = i - s_left[i] - 1;
            int s_right_size = s_right[i] - i - 1;
            int g_left_size = i - g_left[i] - 1;
            int g_right_size = g_right[i] - i - 1;
            count = 1LL*count + 1LL*nums[i]*(g_left_size + g_right_size + g_left_size*g_right_size - s_left_size - s_right_size - s_left_size*s_right_size);
        }
        return count;
    }
};