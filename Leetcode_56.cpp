class Solution {
private:
    static bool compare(vector<int>&a,vector<int>&b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        vector<vector<int>>merged;
        int a = intervals[0][0];
        int b = intervals[0][1];
        for(int i=1;i<intervals.size();i=i+1){
            if(intervals[i][0] <= b)
                b = max(intervals[i][1],b);
            else{
                vector<int>v{a,b};
                merged.push_back(v);
                a=intervals[i][0];
                b=intervals[i][1];
            }
        }
        vector<int>v{a,b};
        merged.push_back(v);
        return merged;
    }
};