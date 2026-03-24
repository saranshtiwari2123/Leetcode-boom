class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) { 
        if(root==NULL) return false;     
        if(targetSum-root->val==0 && root->left==NULL && root->right==NULL) return true; 
        bool x = hasPathSum(root->left, targetSum-root->val);
        bool y = hasPathSum(root->right, targetSum-root->val);
        return x || y;
    }
};