class Solution {
private:
    int checkForSumProperty(Node* root){
        if(root->left == NULL && root->right == NULL)
            return root->data;
        int left_sum = 0;
        if(root->left)
            left_sum = checkForSumProperty(root->left);
        int right_sum = 0;
        if(root->right)
            right_sum = checkForSumProperty(root->right);
        if(left_sum < 0 || right_sum < 0)
            return -1;
        if(root->data == left_sum + right_sum)
            return root->data;
        else
            return -1;
    }
  public:
    bool isSumProperty(Node *root) {
        // code here
        return checkForSumProperty(root) <= 0 ? false : true;
    }
};