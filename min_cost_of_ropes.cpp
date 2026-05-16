class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>minh;
        for(int i=0;i<arr.size();i=i+1){
            minh.push(arr[i]);
        }
        int total_cost = 0;
        while(minh.size() > 1){
            int shortest_1 = minh.top();
            minh.pop();
            int shortest_2 = minh.top();
            minh.pop();
            total_cost +=shortest_1 + shortest_2;
            minh.push(shortest_1+shortest_2);
        }
        return total_cost;
    }
};