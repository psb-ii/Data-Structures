class Solution {
public:
    int beautySum(string s) {
        int beauty_sum = 0;
        for(int i=0;i<s.length();i=i+1){
            unordered_map<char,int>ma;
            int maxi = 0;
            for(int j=i;j<s.length();j=j+1){
                ma[s[j]]++;
                maxi = max(maxi,ma[s[j]]);
                int mini = INT_MAX;
                if(ma.size() > 1){
                    for(auto it = ma.begin(); it != ma.end(); it++){
                        mini = min(mini,it->second);
                    }
                    beauty_sum += maxi - mini; 
                }
            }
            ma.clear();
        }
        return beauty_sum;
    }
};