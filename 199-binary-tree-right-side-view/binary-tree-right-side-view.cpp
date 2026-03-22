class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }
    vector<int> preorder(vector<int>& ans, TreeNode* root, int curr){
        if(root==NULL) return ans;
        ans[curr] = root->val;
        preorder(ans,root->left,curr+1);
        preorder(ans,root->right,curr+1);
        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        int x = level(root);
        vector<int> ans(x);
        return preorder(ans,root,0);
    }
};