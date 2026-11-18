class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};

        vector<vector<int>> result;

        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                ans.push_back(temp->val);
                if(temp->left) q.push(temp->left); 
                if(temp->right) q.push(temp->right);
                 
            }
            result.push_back(ans);
            ans.clear();
        }
        return result;
    }
};