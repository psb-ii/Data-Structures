class Solution {
private:
    Node* fetchCompleteLeftSubtree(Node* root,vector<int>&v){
        Node* l= NULL;
        while(root){
            v.push_back(root->data);
            l=root;
            if(root->left)
                root = root -> left;
            else 
            if(root->right)
                root = root -> right;
            else
                break;
        }
        return l;
    }
    Node* fetchCompleteRightSubtree(Node* root,vector<int>&v){
        Node* r;
        while(root){
            v.push_back(root->data);
            r=root;
            if(root->right)
                root = root -> right;
            else
            if(root->left)
                root = root -> left;
            else
                break;
        }
        reverse(v.begin(),v.end());
        return r;
    }
    void fetchAllLeafNodes(Node* root,vector<int>& leaves,Node* l,Node* r,Node* root_node){
        if(root){
            if(root->left == NULL && root->right == NULL && root != l && root != r && root != root_node)
                leaves.push_back(root->data);
            fetchAllLeafNodes(root->left,leaves,l,r,root_node);
            fetchAllLeafNodes(root->right,leaves,l,r,root_node);
        }
    }
    void pushInBoundaryVector(vector<int>& res,vector<int>& v){
        for(int i=0;i<v.size();i=i+1){
            res.push_back(v[i]);
        }
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>left_side, right_side, leaves;
        Node* left_last = fetchCompleteLeftSubtree(root->left,left_side);
        Node* right_last = fetchCompleteRightSubtree(root -> right,right_side);
        // cout << left_last -> data<<" "<<right_last -> data<<endl;
        fetchAllLeafNodes(root,leaves,left_last,right_last,root);
        vector<int>res({root->data});
        pushInBoundaryVector(res,left_side);
        pushInBoundaryVector(res,leaves);
        pushInBoundaryVector(res,right_side);
        return res;
    }
};