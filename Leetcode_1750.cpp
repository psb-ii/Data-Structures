class Solution {
public:
    int minimumLength(string s) {
        vector<pair<char,int>>vp;
        char prev = s[0];
        int freq = 1;
        for(int i=1;i<s.length();i=i+1){
            if(s[i] == prev)
                freq +=1;
            else{
                vp.push_back({prev,freq});
                freq = 1;
                prev = s[i];
            }
        }
        vp.push_back({prev,freq});
        // int start = 0;
        int start = 0;
        while(start * 2 <= vp.size() && vp[start].first == vp[vp.size() - start - 1].first){
            if(start == (vp.size() - start - 1)){
                if(vp[start].second == 1)
                    return 1;
                else
                    return 0;
            }
            start++;
        }
        int result = 0;
        for(int i=start;i<=vp.size()-start-1;i=i+1)
            result +=vp[i].second;
        return result;
    }
};