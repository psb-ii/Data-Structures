class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int>x_coordinates[n+1];  // x remains constant throughout
        vector<int>y_coordinates[n+1];  // y remains constant throughout
        for(int i=0;i<buildings.size();i=i+1){
            x_coordinates[buildings[i][0]].push_back(buildings[i][1]);
            y_coordinates[buildings[i][1]].push_back(buildings[i][0]);
        }
        for(int i=1;i<=n;i=i+1){
            sort(x_coordinates[i].begin(),x_coordinates[i].end());
            sort(y_coordinates[i].begin(),y_coordinates[i].end());
        }
        int enclosed_buildings = 0;
        for(int i=0;i<buildings.size();i=i+1){
            int x = buildings[i][0];
            int y = buildings[i][1];
            auto greater_x = upper_bound(y_coordinates[y].begin(),y_coordinates[y].end(),x);
            auto greater_y = upper_bound(x_coordinates[x].begin(),x_coordinates[x].end(),y);
            if(y_coordinates[y][0] < x && x_coordinates[x][0] < y && greater_x != y_coordinates[y].end() && greater_y != x_coordinates[x].end())
                enclosed_buildings += 1; 
        }
        return enclosed_buildings;
    }
};