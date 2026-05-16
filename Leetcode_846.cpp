lass Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(groupSize * (hand.size()/groupSize) != hand.size())
            return false;
        unordered_map<int,int>ma;
        for(int i=0;i<hand.size();i=i+1)
            ma[hand[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        for(auto it=ma.begin();it!=ma.end();it++){
            minh.push({it->first,it->second});
        }
        while(minh.size()){
            vector<pair<int,int>>vp;
            pair<int,int> t = minh.top();
            int curr = t.first;
            int si = t.second-1;
            if(si)
                vp.push_back({curr,si});
            minh.pop();
            for(int i=1;i<groupSize;i=i+1){
                t = minh.top();
                minh.pop();
                if(t.first != curr + 1)
                    return false;
                else{
                    curr = t.first;
                    si = t.second-1;
                    if(si)
                        vp.push_back({curr,si});
                }
            }
            for(int i=0;i<vp.size();i=i+1){
                minh.push({vp[i].first,vp[i].second});
            }
        }
        return true;
    }
};