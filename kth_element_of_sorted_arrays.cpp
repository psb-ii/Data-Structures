class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        if(a.size() > b.size())
            return kthElement(b,a,k);
        int low = 0;
        int high = a.size();
        while(low <= high){
            int mid1 = low + ((high - low) >> 1);
            int mid2 = k - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 - 1 >= 0)
                l1 = a[mid1 - 1];
            if(mid2 - 1 >= 0)
                l2 = b[mid2 - 1];
            if(mid1 < a.size())
                r1 = a[mid1];
            if(mid2 < b.size())
                r2 = b[mid2];
            if(l1 <= r2 && l2 <= r1)
                return max(l1,l2);
            else
            if(l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return -1;
    }
};