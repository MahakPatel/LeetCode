/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL)
            return (p == q);
        // apply any DFS method(here i apply preOrder travesal)
        return (p->val == q->val) && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right); // check each node of p with each
                                               // node of q at same time
    }
};