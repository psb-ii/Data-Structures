class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>maxh;
        for(int i=0;i<arr.size();i=i+1){
            maxh.push(arr[i]);
            if(maxh.size() > k)
                maxh.pop();
        }
        return maxh.top();
    }
};