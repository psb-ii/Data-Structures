class Solution {
  public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        vector<int>res;
        for(int i=0;i<indices.size();i=i+1){
            int count = 0;
            for(int j=indices[i];j<arr.size();j=j+1){
                count += arr[indices[i]] < arr[j] ? 1 : 0;
            }
            res.push_back(count);
        }
        return res;
    }
};