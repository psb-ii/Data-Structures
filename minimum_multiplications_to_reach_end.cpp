class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        vector<int>vis(1001,0);
        queue<pair<int,int>>qu;
        vis[start]=1;
        qu.push({start,0});
        while(qu.size()){
            int num = qu.front().first;
            int steps = qu.front().second;
            qu.pop();
            if(num == end)
                return steps;
            for(int i=0;i<arr.size();i=i+1){
                if(!vis[(num*arr[i])%1000]){
                    vis[(num*arr[i])%1000]=1;
                    qu.push({num*arr[i]%1000,steps+1});
                }
            }
        }
        return -1;
    }
};