class Solution {
private:
    bool isValidCoordinateOrNot(int abs,int ord,vector<vector<int>>&grid){
        if(abs>=0 && abs<grid.size() && ord>=0 && ord<grid[0].size())
            return true;
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minh;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int res = 0;
        minh.push({grid[0][0],{0,0}});
        visited[0][0]=1;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        while(minh.size()){
            int dist = minh.top().first;
            int abs = minh.top().second.first;
            int ord = minh.top().second.second;
            minh.pop();
            res = max(res,dist);
            if(abs == grid.size() - 1 && ord == grid[abs].size() - 1){
                break;
            }
            for(int i=0;i<4;i=i+1){
                int new_abs = abs + dx[i];
                int new_ord = ord + dy[i];
                if(isValidCoordinateOrNot(new_abs,new_ord,grid) && !visited[new_abs][new_ord]){
                    minh.push({grid[new_abs][new_ord],{new_abs,new_ord}});
                    visited[new_abs][new_ord]=1;
                }
            }
        }
        return res;
    }
};