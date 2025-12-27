class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            int missing_mid = arr[mid] - mid - 1;
            if(missing_mid >= k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(high == -1)
            return k;
        int missing_high = arr[high] - high - 1;
        int remaining = k - missing_high;
        return arr[high] + remaining;
    }
};