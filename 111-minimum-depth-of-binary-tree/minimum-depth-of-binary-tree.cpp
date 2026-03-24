class Solution {
public:
    int travel(TreeNode* root, int level){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            level += 1;
            for(int i=0;i<size;i++){
                TreeNode* a = q.front();
                if(a->left==NULL && a->right==NULL) return level;
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                q.pop();
            }      
        }
        return level;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return travel(root,0);
    }
};