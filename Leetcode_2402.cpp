class Solution {
struct Compare{
    bool operator()(pair<long long int,int>&a,pair<long long int,int>&b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};
using min_Heap_1 = priority_queue<int, vector<int> , greater<int>>;
using min_Heap_2 = priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, Compare>;
private:
    void updateEmptyRooms(min_Heap_1 &pq,int n){
        for(int i=0;i<n;i=i+1){
            pq.push(i);
        }
    }
   
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        Solution sol;
        int max_meetings = 0;
        int max_occupied = -1;
        min_Heap_1 empty_rooms;
        min_Heap_2 occupied;
        unordered_map<int,int>ma;
        sol.updateEmptyRooms(empty_rooms,n);
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<meetings.size();i=i+1){
            while(occupied.size() && occupied.top().first <= meetings[i][0]){
                int t_room = occupied.top().second;
                empty_rooms.push(t_room);
                occupied.pop();
            }
            long long int meeting_end_time = 1ll*meetings[i][1];
            if(empty_rooms.size() == 0){
                long long int mini = 1ll*occupied.top().first;
                empty_rooms.push(occupied.top().second);
                occupied.pop();
                meeting_end_time = 1ll*mini + 1ll*(1ll*meetings[i][1] - 1ll*meetings[i][0]);
            }
            int room = empty_rooms.top();
            empty_rooms.pop();
            occupied.push({meeting_end_time,room});
            ma[room]++;
            if(ma[room] > max_meetings){
                max_occupied = room;
                max_meetings = ma[room];
            }
            else
            if(ma[room] == max_meetings){
                max_occupied = min(max_occupied,room);
            }
        }
        return max_occupied;
    }
};