class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        vector<int>prev(3,-1);
        prev[0] = max(mat[0][1],mat[0][2]);
        prev[1] = max(mat[0][0],mat[0][2]);
        prev[2] = max(mat[0][0],mat[0][1]);
        for(int i=1;i<mat.size();i=i+1){
            vector<int>temp(3,-1);
            for(int last=0;last<3;last++){
                int maxi = INT_MIN;
                for(int j=0;j<3;j=j+1){
                    if(j != last){
                        int points = mat[i][j] + prev[j];
                        maxi = max(maxi,points);
                    }
                }
                temp[last]=maxi;
            }
            prev = temp;
        }
        return max({prev[0],prev[1],prev[2]});
    }
};