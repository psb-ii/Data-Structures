class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        map<int,int>ma;
        queue<pair<Node*,int>>qu;
        qu.push({root,0});
        while(qu.size()){
            Node* front_node = qu.front().first;
            int ordinate = qu.front().second;
            qu.pop();
            if(ma.find(ordinate) == ma.end())
                ma[ordinate] = front_node -> data;
            if(front_node -> left != NULL)
                qu.push({front_node->left,ordinate-1});
            if(front_node -> right != NULL)
                qu.push({front_node->right,ordinate+1});
        }
        vector<int>top_view;
        for(auto it=ma.begin();it!=ma.end();it++){
            top_view.push_back(it->second);
        }
        return top_view;
    }
};