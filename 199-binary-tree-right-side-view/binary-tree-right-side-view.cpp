class Solution {
public:
    vector<int> ans;
    vector<int> preorder(TreeNode* root, int curr){
        if(root==NULL) return ans;

        if(curr==ans.size()) ans.push_back(root->val);

        preorder(root->right,curr+1);
        preorder(root->left,curr+1);
        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        return preorder(root,0);
    }
};