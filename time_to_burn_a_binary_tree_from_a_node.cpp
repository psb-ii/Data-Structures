class Solution {
private:
    Node* updateParentChildMap(Node *root,int target,unordered_map<Node *,Node *>&ma){
        queue<Node *>qu;
        qu.push(root);
        Node *node = NULL;
        while(qu.size()){
            Node *f= qu.front();
            qu.pop();
            if(f->data == target)
                node = f;
            if(f->left){
                ma[f->left] = f;
                qu.push(f->left);
            }
            if(f->right){
                ma[f->right] = f;
                qu.push(f->right);
            }
        }
        return node;
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node *,Node *>ma;
        Node *node = updateParentChildMap(root,target,ma);
        unordered_set<Node *>se;
        queue<pair<Node *,int>>qu;
        qu.push({node,0});
        se.insert(node);
        int dist = -1;
        while(qu.size()){
            Node *f = qu.front().first;
            int distance = qu.front().second;
            qu.pop();
            if(ma.find(f) != ma.end() && se.find(ma[f]) == se.end()){
                se.insert(ma[f]);
                qu.push({ma[f],distance + 1});
            }
            if(f->left && se.find(f->left) == se.end()){
                se.insert(f->left);
                qu.push({f->left,distance + 1});
            }
            if(f->right && se.find(f->right) == se.end()){
                se.insert(f->right);
                qu.push({f->right,distance + 1});
            }
            dist = distance;
        }
        return dist;
    }
};