class Solution {
public:
    int sumT(TreeNode* root,int num){
        if(root->left==NULL && root->right==NULL){
            num = (num*10)+root->val;
            return num;
        }
        num = (num*10)+root->val;
        int left = 0, right = 0;
        if(root->left) left = sumT(root->left, num);
        if(root->right) right = sumT(root->right, num);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        return sumT(root, 0);
    }
};