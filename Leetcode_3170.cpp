class Solution {
private:
    static bool compare(pair<char,int> &a , pair<char,int> &b){
        return b.second > a.second;
    }
public:
    struct compare_heap{
        bool operator()(const pair<char,int>& a, const pair<char,int>& b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char,int>, vector<pair<char,int>>, compare_heap > minh;
        for(int i=0;i<s.length();i=i+1){
            if(s[i] == '*')
                minh.pop();
            else
                minh.push({s[i],i});
        }
        string str = "";
        vector<pair<char,int>>vp;
        while(minh.size()){
            vp.push_back({minh.top().first,minh.top().second});
            minh.pop();
        }
        sort(vp.begin(),vp.end(),compare);
        for(int i=0;i<vp.size();i=i+1){
            str += vp[i].first;
        }
        return str;
    }
};