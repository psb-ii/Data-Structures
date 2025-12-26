class Solution {
public:
    int bestClosingTime(string customers) {
        int total_Y = 0;
        for(int i=0;i<customers.length();i=i+1){
            total_Y +=1;
        }
        int total_N = customers.length() - total_Y;
        int closing_ind = 0;
        int curr_N = 0;
        int curr_Y = 0;
        int mini_penalty = total_Y;
        for(int i=0;i<customers.length();i=i+1){
            if(customers[i] == 'N')
                curr_N++;
            else
                curr_Y++;
            int curr_penalty = curr_N + (total_Y - curr_Y);
            if(mini_penalty > curr_penalty){
                mini_penalty = curr_penalty;
                closing_ind = i + 1;
            }
        }
        return closing_ind;
    }
};