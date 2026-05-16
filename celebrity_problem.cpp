class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int top = 0;
        int bottom = mat.size() - 1;
        while(top < bottom){
            if(mat[top][bottom])
                top++;
            else
            if(mat[bottom][top])
                bottom--;
            else{
                top++;
                bottom--;
            }
        }
        for(int i=0;i<mat.size();i=i+1){
            if(i == top)
                continue;
            if(mat[i][top] == 0)   
                return -1;
        }
        for(int i=0;i<mat[top].size();i=i+1){
            if(i == top)
                continue;
            if(mat[top][i] == 1)
                return -1;
        }
        return top;
    }
};