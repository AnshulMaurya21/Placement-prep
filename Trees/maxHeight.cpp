class Solution {
public:
    int maxDepth(TreeNode* node) {
        if (node == NULL) {
        return 0;
        }
        int leftNodeHeight = maxDepth(node->left);

        int rightNodeHeight = maxDepth(node->right);

        int currentNodeHeight = max(leftNodeHeight, rightNodeHeight) + 1;

        return currentNodeHeight;
    }
};