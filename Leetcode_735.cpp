class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i=i+1){
            int curr = asteroids[i];
            while(st.size() && curr < 0 && st.top() > 0){
                if(st.top() < abs(curr))
                    st.pop();
                else
                if(st.top() == abs(curr)){
                    st.pop();
                    curr = 0;
                }
                else
                    curr = 0;
            }
            if(curr != 0)
                st.push(curr);
        }
        vector<int>res;
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};