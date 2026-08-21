class Solution {
public:
    vector<int> preorder(vector<int>& ans, TreeNode* root, int curr){
        if(root==NULL) return ans;

        if(curr==ans.size()) ans.push_back(root->val);
        else ans[curr] = root->val;

        preorder(ans,root->left,curr+1);
        preorder(ans,root->right,curr+1);
        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        return preorder(ans,root,0);
    }
};