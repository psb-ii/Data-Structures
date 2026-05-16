// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        unordered_map<int,int>ma;
        for(int i=0;i<n;i=i+1){
            ma[arr[i]] = i;
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i=i+1){
            if(abs(i-ma[arr[i]]) > k)
                return "No";
        }
        return "Yes";
    }
};