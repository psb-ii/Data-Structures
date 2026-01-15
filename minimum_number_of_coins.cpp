class Solution {
  public:
    int findMin(int n) {
        // code here
        int coins = 0;
        int k = n;
        int i=0;
        vector<int>coin{10,5,2,1};
        while(k){
            int c = k / coin[i];
            k -= c*coin[i];
            coins +=c;
            i++;
        }
        return coins;
    }
};