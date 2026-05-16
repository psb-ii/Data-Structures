class Solution {
private:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>>vp;
        for(int i=0;i<start.size();i=i+1){
            vp.push_back({start[i],end[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        int meetings = 0;
        int curr_end = -1;
        for(int i=0;i<vp.size();i=i+1){
            // cout <<vp[i].first<<" "<<vp[i].second<<endl;
            if(vp[i].first > curr_end){
                meetings++;
                curr_end = vp[i].second;
            }    
        }
        return meetings;
    }
};