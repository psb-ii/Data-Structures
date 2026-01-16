class Solution {
private: 
    static bool cmp(vector<double>&a,vector<double>&b){
        return a[0] >= b[0];
    }
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<double>>v;
        for(int i=0;i<val.size();i=i+1){
            double val_wt_ratio = (1.0*val[i]) / wt[i];
            vector<double> d{val_wt_ratio,1.0*val[i],1.0*wt[i]};
            v.push_back(d);
        }
        sort(v.begin(),v.end(),cmp);
        int cap = capacity;
        int i = 0; 
        double max_possible= 0;
        while(i<v.size() && int(cap)){
            if(cap >= v[i][2]){
                max_possible += v[i][1];
                cap -=int(v[i][2]);
            }
            else{
                max_possible +=v[i][0]*cap;
                cap -=int(cap);
            }
            i +=1;
        }
        return max_possible;
    }
};