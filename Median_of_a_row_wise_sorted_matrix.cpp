class Solution{
private:
    int getJustSmallerElementIndex(vector<int>&row , int num){
        int low = 0;
        int high = row.size() - 1; 
        int l_index = -1;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(row[mid] < num){
                l_index = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return l_index;
    }
public:
    int median(vector<vector<int>>&matrix) {
      int low = 1;
      int high = 100;
      int mid_index = ((matrix.size() * matrix[0].size()) / 2) + 1;
      int mid = -1;
      int equal = 0;
      int total = matrix.size() * matrix[0].size();
      while(low <= high){
        int lesser = 0;
        int greater = 0;
        mid = low + ((high - low) >> 1);
        for(int i=0;i<matrix.size();i=i+1){
            int lesser_ind = getJustSmallerElementIndex(matrix[i],mid);
            int up_ind = std::upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            greater += matrix[i].size() - up_ind;
            lesser += lesser_ind + 1;
            equal = total - greater- lesser;
        }
        // cout <<low<<" "<<mid<<" "<<high<<" "<<greater<<" "<<lesser <<endl;
        if(lesser < mid_index && (lesser + equal) >= mid_index)
            return mid;
        else if(lesser < mid_index)
            low = mid+1;
        else
            high = mid-1;
      }
      return -1;
    }
};