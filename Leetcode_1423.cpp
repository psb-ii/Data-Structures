class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int curr_sum = accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int res = curr_sum;
        int left = 0;
        int i=0;
        while(i<k){
            curr_sum += cardPoints[cardPoints.size()-1-i] - cardPoints[k-i-1];
            res = max(res,curr_sum);
            i++;
        }
        return res;
    }
};