class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        string res = "";
        vector<int>vis(26,0);
        vector<int>adj[26];
        for(int i=0;i<words.size()-1;i=i+1){
            string word1 = words[i];
            string word2 = words[i+1];
            int len = min(word1.length(),word2.length());
            int k = 0;
            for(k=0;k<len;k=k+1){
                if(word1[k] != word2[k]){
                    bool flag = false;
                    for(auto n:adj[word1[k]-'a']){
                        if(n == (word2[k]-'a')){
                            flag = true;
                        }
                    }
                    if(!flag)
                        adj[word1[k]-'a'].push_back(word2[k]-'a');
                    break;
                }
            }
            if(k == len && word1.length() > word2.length())
                return "";
        }
        int valid = 0;
        for(int i=0;i<words.size();i=i+1){
            for(int k=0;k<words[i].length();k=k+1){
                vis[words[i][k]-'a']=1;
            }
        }
        for(int i=0;i<vis.size();i=i+1){
            valid += vis[i] == 1 ? 1: 0;
        }
        queue<int>qu;
        vector<int>indegrees(26,0);
        for(int i=0;i<26;i=i+1){
            for(int n: adj[i]){
                indegrees[n]++;
            }
        }
        for(int i=0;i<26;i=i+1){
            if(vis[i] && indegrees[i] == 0){
                qu.push(i);
            }
        }
        while(qu.size()){
            int node = qu.front();
            res +=char(97+node);
            qu.pop();
            for(int n: adj[node]){
                indegrees[n]--;
                if(indegrees[n] == 0)
                    qu.push(n);
            }
        }
        if(res.length() != valid)
            res = "";
        return res;
    }
};