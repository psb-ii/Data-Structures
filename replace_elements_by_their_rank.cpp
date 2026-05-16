// User function Template for C++

class Solution {
  public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int>temp;
        for(int i=0;i<arr.size();i=i+1){
            temp.emplace_back(arr[i]);
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,int>ma;
        int curr = 1;
        int prev = temp[0];
        ma[prev]=curr;
        for(int i=1;i<temp.size();i=i+1){
            if(temp[i] != prev){
                ma[temp[i]]=++curr;
            }
            prev = temp[i];
        }
        vector<int>res;
        for(int i=0;i<arr.size();i=i+1){
            res.emplace_back(ma[arr[i]]);
        }
        return res;
    }
};
