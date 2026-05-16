class Solution {
private:
    void countAllPathSum(TreeNode* root,int &targetSum,unordered_map<long long int,int>&ma,int &count,long long int &curr_sum){
        if(root){
            long long int new_path_sum = 1ll*curr_sum + root -> val;
            count +=ma[new_path_sum - targetSum];
            ma[new_path_sum]++;
            countAllPathSum(root->left,targetSum,ma,count,new_path_sum);
            countAllPathSum(root->right,targetSum,ma,count,new_path_sum);
            ma[new_path_sum]--; 
        }
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long int,int>ma;
        ma[0]=1;
        int count = 0;
        long long int curr_sum = 0ll;
        countAllPathSum(root,targetSum,ma,count,curr_sum);
        return count;
    }
};