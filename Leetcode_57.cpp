class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        bool flag = false;
        if(intervals.size() && intervals[0][0] > newInterval[1]){
            flag = true;
            vector<int>v{newInterval[0],newInterval[1]};
            res.push_back(v);
        }
        for(int i=0;i<intervals.size();){
            if(flag == false && intervals[i][0] > newInterval[1]){
                flag = true;
                vector<int>v{newInterval[0],newInterval[1]};
                res.push_back(v);
            }
            if((newInterval[0] >= intervals[i][0]  && newInterval[0] <= intervals[i][1]) || (newInterval[1] >= intervals[i][0] && newInterval[1] < intervals[i][1]) || (newInterval[0] <= intervals[i][1] && newInterval[1] >= intervals[i][1])){
                flag = true;
                int curr_min = min(intervals[i][0],newInterval[0]);
                int curr_max = max(intervals[i][1],newInterval[1]);
                i=i+1;
                while(i<intervals.size() && intervals[i][0] <= curr_max){
                    curr_max = max(curr_max,intervals[i][1]);
                    i++;
                }
                vector<int>v{curr_min,curr_max};
                res.push_back(v);
            }
            else{
                res.push_back(intervals[i]);
                i++;
            }
        }
        if(!flag){
            vector<int>v{newInterval[0],newInterval[1]};
            res.push_back(v);
        }
        return res;
    }
};