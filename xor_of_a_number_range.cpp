class Solution {
  void updateBits(int num,vector<long long int>&bits){
      for(int i=0;i<bits.size();i=i+1){
          long long int div = 1ll << (i + 1);
          long long int bit_set = 1ll << i;
          long long int full = ((num+1) / div) * bit_set;
          long long int remaining = (num + 1) - full * 2;
          long long int half = 0;
          if(remaining > (div>>1))
            half = remaining % (div >> 1);
          bits[i] = full + half;
      }
  }
  public:
    int findXOR(int l, int r) {
        // code here
        vector<long long int>bits1(32,0ll);
        vector<long long int>bits2(32,0ll);
        updateBits(l-1,bits1);
        updateBits(r,bits2);
        int num = 0;
        for(int i=0;i<bits1.size();i=i+1){
            int diff = bits2[i] - bits1[i];
            if(diff & 1)
                num = num | 1ll << i;
        }
        return num;
    }
};