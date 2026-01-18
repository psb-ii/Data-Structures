class Solution {
private:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end(),cmp);
        int curr_end = intervals[0][1];
        int curr_start = intervals[0][0];
        for(int i=1;i<intervals.size();i=i+1){
            if(intervals[i][0] <= curr_end)
                curr_end = max(curr_end,intervals[i][1]);
            else{
                vector<int>v{curr_start,curr_end};
                res.push_back(v);
                curr_start = intervals[i][0];
                curr_end = intervals[i][1];
            }
        }
        vector<int>v{curr_start,curr_end};
        res.push_back(v);   
        return res;
    }
};