class Solution {
public:
    int order(TreeNode* root, int& sum, bool check){
        if(root==NULL) return 0;
        if(check==true && root->left==NULL && root->right==NULL) sum += root->val;   
        order(root->left, sum, true);
        order(root->right, sum, false);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        return order(root,sum, false);
    }
};