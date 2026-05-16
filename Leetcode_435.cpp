class Solution {
private:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int res = 0;
        int curr_min = intervals[0][0];
        int curr_max = intervals[0][1];
        for(int i=1;i<intervals.size();i=i+1){
            if(intervals[i][0] >= curr_max){
                curr_min = intervals[i][0];
                curr_max = intervals[i][1];
            }
            else{
                res++;
                if(intervals[i][1] < curr_max)
                    curr_max = intervals[i][1];
            }
        }
        return res;
    }
};