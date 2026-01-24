class Solution {
private:
    bool isPossible(int num,int n,vector<int>& quantities){
        long long int k = 0ll;
        for(int i=0;i<quantities.size();i=i+1){
            k += (quantities[i] % num) == 0 ? 1ll*quantities[i] / num : (1ll*quantities[i] / num) + 1;
        }
        return k<=n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(),quantities.end());
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(isPossible(mid,n,quantities))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;      
    }
};