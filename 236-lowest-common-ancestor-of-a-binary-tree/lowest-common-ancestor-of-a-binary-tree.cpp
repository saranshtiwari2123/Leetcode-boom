class Solution {
public:
    bool search(TreeNode* root, int val){
        if(root==NULL) return false;
        if(root->val == val) return true;
        return search(root->left, val) || search(root->right, val);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val || root->val==q->val) return root;
        if(search(root->left, p->val) && search(root->right, q->val)) return root;
        if(search(root->left, q->val) && search(root->right, p->val)) return root;
        if(!search(root->left, p->val) && search(root->right, q->val)) return lowestCommonAncestor(root->right, p, q);
        if(search(root->left, p->val) && !search(root->right, q->val)) return lowestCommonAncestor(root->left, p, q);
        return NULL;
    }
};