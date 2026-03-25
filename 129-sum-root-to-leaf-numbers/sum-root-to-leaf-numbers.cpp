class Solution {
public:
    int solve(TreeNode* root, int current) {
        if (!root) return 0;

        current = current * 10 + root->val;

        // If leaf node
        if (!root->left && !root->right) {
            return current;
        }

        // Recur for left and right
        return solve(root->left, current) + solve(root->right, current);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};