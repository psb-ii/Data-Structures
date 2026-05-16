class Solution {
using MAXHEAP = priority_queue<pair<int,char>>;
using MINHEAP = priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>;
using UN_MAP = unordered_map<char,int>;
private:
    void updatedSchedulingHeap(MAXHEAP& maxh, MINHEAP& minh,int curr, UN_MAP& ma){
        while(minh.size() && minh.top().first == curr){
            char ch = minh.top().second;
            maxh.push({ma[ch],ch});
            minh.pop();
        }
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>ma;
        for(int i=0;i<tasks.size();i=i+1){
            ma[tasks[i]]++;
        }
        int curr = 0;
        MAXHEAP maxh;
        MINHEAP minh;
        for(auto it=ma.begin();it!=ma.end();it++){
            maxh.push({it->second,it->first});
        }
        int total_schedules = 0;
        while(total_schedules < tasks.size()){
            curr++;
            if(maxh.size() == 0 || (minh.size() && curr >= minh.top().first)){
                if(maxh.size() == 0)
                    curr = max(curr,minh.top().first);
                updatedSchedulingHeap(maxh,minh,curr,ma);
            }
            int freq = maxh.top().first;
            char ch = maxh.top().second;
            maxh.pop();
            ma[ch]--;
            cout <<freq <<" "<<curr<<endl;
            if(freq > 1)
                minh.push({curr+n+1,ch});
            total_schedules++;
        }
        return curr;
    }
};