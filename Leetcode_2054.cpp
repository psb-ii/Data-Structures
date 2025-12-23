class Solution {
private:
    static bool compare(vector<int>&a,vector<int>&b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),compare);
        vector<int>start;
        for(int i=0;i<events.size();i=i+1){
            start.push_back(events[i][0]);
        }
        vector<int>max_score_possible;
        // for(int i=0;i<start.size();i=i+1){
        //     cout <<start[i]<<" ";
        // }
        // cout <<endl;
        int curr = 0;
        for(int i=events.size()-1;i>=0;i=i-1){
            curr = max(curr,events[i][2]);
            max_score_possible.push_back(curr);
        }
        reverse(max_score_possible.begin(),max_score_possible.end());
        // for(int i=0;i<max_score_possible.size();i=i+1){
        //     cout << max_score_possible[i]<<" ";
        // }
        // cout <<endl;
        int maxi = 0;
        for(int i=0;i<events.size();i=i+1){
            int curr_score = events[i][2];
            auto it = lower_bound(start.begin(),start.end(),events[i][1] + 1);
            if(it != start.end()){
                // cout <<i << " "<< it - start.begin() <<endl;
                curr_score += max_score_possible[it - start.begin()];
            }
            maxi = max(maxi,curr_score);
        }
        return maxi;
    }
};