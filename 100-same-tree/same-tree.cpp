class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && q) return false;
        if(p && !q) return false;
        if(!p && !q) return true;
        if(p->val!=q->val) return false;
        bool lans = isSameTree(p->left,q->left);
        bool rans = isSameTree(p->right, q->right);
        return lans && rans;
    }
};