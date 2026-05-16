class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>>prefix(mat.size()+1,vector<int>(mat[0].size()+1,0));
        for(int i=1;i<prefix.size();i=i+1){
            for(int j=1;j<prefix[i].size();j=j+1){
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + mat[i-1][j-1]; 
            }
        }
        int res = 0;
        for(int i=0;i<mat.size();i=i+1){
            for(int j=0;j<mat[i].size();j=j+1){
                if(mat[i][j] <= threshold)
                    res = max(res,1);
                for(int k=1;k<=300;k=k+1){
                    int a = i+1,b = j+1,c = i+k+1, d=j+k+1;
                    if(c>= prefix.size() || d >= prefix[i].size())
                        break;
                    int sum = prefix[c][d] - prefix[a-1][d] - prefix[c][b-1] + prefix[a-1][b-1];
                    // cout <<sum<<" ";
                    if(sum <= threshold)
                        res = max(res,(k+1));
                }
            }
        }
        return res;
    }
};