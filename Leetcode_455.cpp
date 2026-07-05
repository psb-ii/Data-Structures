class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ind = 0;
        int count = 0;
        for(int i=0;i<g.size();i=i+1){
            while(ind < s.size()){
                if(g[i] <= s[ind]){
                    count = count + 1;
                    ind++;
                    break;
                }
                ind++;
            }
        }
        return count;
    }
};