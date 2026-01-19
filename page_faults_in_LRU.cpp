class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        // code here
        int faults = 0;
        unordered_set<int>se;
        deque<int>dq;
        for(int i=0;i<N;i=i+1){
            if(se.find(pages[i]) == se.end()){
                faults++;
                se.insert(pages[i]);
                dq.push_front(pages[i]);
                if(dq.size() > C){
                    se.erase(se.find(dq.back()));
                    dq.pop_back();
                }
            }
            else{
                stack<int>st;
                while(true){
                    int ele = dq.back();
                    dq.pop_back();
                    if(ele == pages[i])
                        break;
                    st.push(ele);
                    se.erase(se.find(ele));
                }
                while(st.size()){
                    se.insert(st.top());
                    dq.push_back(st.top());
                    st.pop();
                }
                dq.push_front(pages[i]);
            }
        }
        return faults;
    }
};