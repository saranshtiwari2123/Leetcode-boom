class Solution {
public:
    vector<string> traverse(TreeNode* root, string s, vector<string>& v){
        string a = to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            s+=a;
            v.push_back(s);
            return v;
        }
        
        if(root->left) traverse(root->left, s+a+"->", v);
        if(root->right) traverse(root->right, s+a+"->", v);
        return v;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        return traverse(root, "" , v);
    }
};