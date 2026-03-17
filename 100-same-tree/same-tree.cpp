class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && q) return false;
        if(p && !q) return false;
        if(!p && !q) return true;
        if(p->val!=q->val) return false;
        bool lans = isSameTree(p->left,q->left);
        if(lans==false) return false;
        bool rans = isSameTree(p->right, q->right);
        if(rans==false) return false;
        return true;
    }
};