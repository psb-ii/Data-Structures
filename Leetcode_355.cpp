class Twitter {
public:
    unordered_map<int,unordered_set<int>>ma;
    int curr = 0;
    unordered_map<int,vector<pair<int,int>>>m;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        m[userId].push_back({curr,tweetId});
        curr++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>>maxh;
        for(auto it=ma[userId].begin();it!=ma[userId].end();it++){
            if(m[*it].size() > 0){
                // {timestamp_equivalent,tweet_id,followeeId,index}
                int ind = m[*it].size()-1;
                maxh.push({m[*it][ind].first,m[*it][ind].second,*it,ind});
            }
        }
        if(m[userId].size()){
            int ind = m[userId].size() - 1;
            maxh.push({m[userId][ind].first,m[userId][ind].second,userId,ind});
        }
        vector<int>res;
        while(maxh.size() && res.size() < 10){
            int id = maxh.top()[1];
            int followee = maxh.top()[2];
            int ind = maxh.top()[3];
            maxh.pop();
            res.push_back(id);
            if(ind > 0)
                maxh.push({m[followee][ind-1].first,m[followee][ind-1].second,followee,ind-1});
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        ma[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        ma[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */