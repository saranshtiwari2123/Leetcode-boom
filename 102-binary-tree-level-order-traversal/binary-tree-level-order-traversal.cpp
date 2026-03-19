class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> result;

        queue<TreeNode*> q;
        q.push(root);

        vector<int> v;
        while(!q.empty()){
            int size = q.size();
            v.clear();
            for(int i=0;i<size;i++){
                TreeNode* a = q.front();
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                v.push_back(a->val);
                q.pop();
            }
            result.push_back(v);      
        }
        return result;
    }
};