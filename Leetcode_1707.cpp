class Solution {
    class TrieNode {
        public:
            TrieNode* links[2];

            bool containsKey(int num){
                return links[num] != NULL;
            }

            TrieNode* get(int num){
                return links[num];
            }

            void put(int num,TrieNode* node){
                links[num] = node;
            }
    };
    TrieNode* root;
private:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1] < b[1];
    }

    void insertNumberIntoTheTrie(int num){
        TrieNode* node = root;
        for(int i=31;i>=0;i=i-1){
            int n = num & (1 << i) ? 1 : 0;
            if(!(node -> containsKey(n)))
                node -> put(n,new TrieNode());
            node = node -> get(n);
        }
    }

    void insertNumbersIntoTheTrie(int start_ind,int end_ind,vector<int>&nums){
        for(int i=start_ind;i<=end_ind;i=i+1){
            insertNumberIntoTheTrie(nums[i]);
        }
    }
    
    int maximumXorPossibleFromNumbers(int number){
        TrieNode* node = root;
        int res = 0;
        for(int i=31;i>=0;i=i-1){
            int n = (number & (1 << i)) ? 1 : 0;
            int opp_n = 1 - n;
            if(node -> containsKey(opp_n)){
                node = node -> get(opp_n);
                res = res | (1 << i);
            }
            else{
                node = node -> get(n);
            }
        }
        return res;
    }
public:
    Solution() {
        root = new TrieNode();
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        map<pair<int,int>,int>ma;
        sort(nums.begin(),nums.end());
        vector<vector<int>>temp = queries;
        sort(temp.begin(),temp.end(),cmp);
        int ind = 0;
        cout <<temp.size();
        for(int i=0;i<temp.size();i=i+1){
            cout<<temp[i][0];
            int end_ind = lower_bound(nums.begin(),nums.end(),temp[i][1]) - nums.begin();
            if(end_ind == nums.size() || nums[end_ind] > temp[i][1])
                end_ind = end_ind - 1;
            insertNumbersIntoTheTrie(ind,end_ind,nums);
            ind = end_ind + 1;
            if(end_ind < 0)
                ma[{temp[i][0],temp[i][1]}] = -1;
            else
                ma[{temp[i][0],temp[i][1]}] = maximumXorPossibleFromNumbers(temp[i][0]);
        }
        for(int i=0;i<queries.size();i=i+1){
            res.push_back(ma[{queries[i][0],queries[i][1]}]);
        }
        return res;
    }
};