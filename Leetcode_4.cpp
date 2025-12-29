class Solution {
private:
    double calculateMedian(vector<int>&nums1,vector<int>&nums2){
        int low = 0;
        int high = nums1.size();
        int total = nums1.size() + nums2.size();
        int mid_ind = (total + 1 ) >> 1;
        while(low <= high){
            int mid1 = low + ((high - low) >> 1);
            int mid2 = mid_ind - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            if(mid1 < nums1.size())
                r1 = nums1[mid1];
            if(mid2 < nums2.size())
                r2 = nums2[mid2];
            if(l1 <= r2 && l2 <= r1){
                // cout << l1 <<" "<<l2<<endl;
                if(total & 1)
                    return 1.0*(max(l1,l2));
                else
                    return 1.0*(max(l1,l2) + min(r1,r2))/2.0;
            }
            else
            if(l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 1.0;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() > nums1.size())
            return calculateMedian(nums1,nums2);
        return calculateMedian(nums2,nums1);
    }
};