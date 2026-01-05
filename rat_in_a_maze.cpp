class Solution {
// using twod_vector = vector<vector<int>>;
private:
    void allPathsThatArePossible(int row,int col,string &curr,vector<string>&vs,vector<vector<int>> &maze,vector<vector<int>> &visited){
        // cout <<row <<" "<<col;
        if(row == maze.size() - 1 && col == maze.size() - 1){
            vs.push_back(curr);
            return;
        }
        if(row < 0 || col < 0 || row >= maze.size() || col >= maze.size() || maze[row][col] == 0)
            return;
        int dx[] = {1,0,0,-1};
        int dy[] = {0,-1,1,0};
        string dir = "DLRU";
        for(int i=0;i<4;i=i+1){
            int new_r = row + dx[i];
            int new_c = col + dy[i];
            if(new_r >= 0 && new_r < maze.size() && new_c >=0 && new_c < maze.size() && visited[new_r][new_c] == 0){
                curr.push_back(dir[i]);
                visited[new_r][new_c] = 1;
                allPathsThatArePossible(new_r,new_c,curr,vs,maze,visited);
                curr.pop_back();
                visited[new_r][new_c] = 0;
            }
        }
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code her
        vector<string>vs;
        vector<vector<int>>visited(maze.size(),vector<int>(maze.size(),0));
        string curr = "";
        int row = 0;
        int col = 0;
        visited[0][0] = 1;
        if(maze[0][0] && maze[maze.size()-1][maze.size()-1])
            allPathsThatArePossible(row,col,curr,vs,maze,visited);
        return vs;
    }
};