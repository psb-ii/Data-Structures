class Solution {
private:
    int getNegativeIndex(vector<int>&balance){
        int pos = -1;
        for(int i=0;i<balance.size();i=i+1)
            pos = balance[i] < 0 ? i : pos;
        return pos;
    }
public:
    long long minMoves(vector<int>& balance) {
        long long int sum = 0;
        for(int i=0;i<balance.size();i=i+1){
            sum +=balance[i];
        }
        // cout << sum ;
        long long int moves = 0;
        if(sum < 0)
            return -1;
        int neg_pos = getNegativeIndex(balance);
        cout << neg_pos;
        if(neg_pos == -1)
            return 0;
        long long int distance = 1;
        unordered_set<int>se;
        int unbalanced = balance[neg_pos];
        while(unbalanced != 0){
            int before_ind = (neg_pos - distance + balance.size()) % balance.size();
            int after_ind = (neg_pos + distance) % balance.size();
            int total = 0;
            if(se.find(before_ind) == se.end()){
                total += balance[before_ind];
                se.insert(before_ind);
            }   
            if(se.find(after_ind) == se.end()){
                total +=balance[after_ind];
                se.insert(after_ind);
            }
            if(total < abs(unbalanced)){
                moves += (distance*total*1ll);
                unbalanced +=total;
            }
            else{
                moves += (distance*abs(unbalanced)*1ll);
                unbalanced = 0;
            }
            distance++;
        }
        return moves;   
    }
};