class Solution {
  public:
    int findMax(Node *root) {
        // code here
        int maxi = root->data;
        while(root->left || root->right){
            if(root->right)
                root= root -> right;
            else
                root = root -> left;
            maxi = max(maxi,root->data);
        }
        return maxi;
    }

    int findMin(Node *root) {
        // code here
        int mini = root->data;
        while(root->left || root->right){
            if(root->left)
                root = root->left;
            else
                root = root->right;
            mini = min(mini,root->data);
        }
        return mini;
    }
};