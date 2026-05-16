class myStack {
  public:
    vector<int>st;
    int ind = -1;
    int max_size;
    myStack(int n) {
        // Define Data Structures
        max_size = n;
        for(int i=0;i<n;i=i+1){
            st.push_back(-1);
        }
    }

    bool isEmpty() {
        // check if the stack is empty
        return ind == -1;
    }

    bool isFull() {
        // check if the stack is full
        return ind == max_size - 1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        ind++;
        st[ind] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if(ind >= 0)
            ind--;
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty())
            return -1;
        return st[ind];
    }
};