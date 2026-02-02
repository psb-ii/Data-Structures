/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        queue<TreeNode *>qu;
        if(root)
            qu.push(root);
        while(qu.size()){
            TreeNode* node = qu.front();
            qu.pop();
            if(node){
                s +=to_string(node->val)+",";
                qu.push(node->left);
                qu.push(node->right);
            }
            else
                s +="#,";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0)
            return NULL;
        vector<string>vs;
        string s="";
        for(int i=0;i<data.length();i=i+1){
            if(data[i] == ','){
                vs.push_back(s);
                s="";
            }
            else
                s +=data[i];
        }
        TreeNode *root = new TreeNode;
        queue<TreeNode *>qu;
        root->val = stoi(vs[0]);
        qu.push(root);
        int i=1;
        while(qu.size()){
            TreeNode* f=qu.front();
            qu.pop();
            string n1=vs[i++];
            string n2=vs[i++];
            if(n1 != "#"){
                TreeNode* node1 = new TreeNode(stoi(n1));
                f->left = node1;
                qu.push(node1);
            }
            else
            f->left = NULL;
            if(n2 != "#"){
                TreeNode* node2 = new TreeNode(stoi(n2));
                f -> right = node2;
                qu.push(node2);
            }
            else
                f->right=NULL;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));