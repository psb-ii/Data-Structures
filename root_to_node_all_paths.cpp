class Solution {
private:
    void allPossibleRootToLeafPaths(Node* root,vector<int>& path,vector<vector<int>>& res){
        path.push_back(root->data);
        if(root->left == NULL && root->right == NULL){
            res.push_back(path);
            path.pop_back();
            return;
        }
        if(root->left){
            allPossibleRootToLeafPaths(root->left,path,res);
        }
        if(root->right){
            allPossibleRootToLeafPaths(root->right,path,res);
        }
        path.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>all_paths;
        vector<int>path;
        allPossibleRootToLeafPaths(root,path,all_paths);
        return all_paths;
    }
};