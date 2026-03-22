class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return {};
        int x = level(root);
        vector<vector<int>> res(x--);

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> v(size);

            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                v[i] = temp->val;
            }
            res[x--] = v;
        }
        return res;
    }
};