#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inOrder;
        stack<TreeNode *> s;
        TreeNode *curr = root;

        if (curr == NULL)
        {
            return inOrder;
        }

        while (curr != NULL || !s.empty())
        {
            if (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = s.top();
                inOrder.push_back(curr->val);
                s.pop();
                curr = curr->right;
            }
        }

        return inOrder;
    }
};