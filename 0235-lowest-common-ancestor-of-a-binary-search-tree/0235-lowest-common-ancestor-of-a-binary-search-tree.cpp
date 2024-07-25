/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) // check for base condition
            return NULL;

        int cur = root->val; // store root node value

        if (cur < p->val && cur < q->val) { // if both nodes( p and q) value is greater than root node value
            return lowestCommonAncestor(root->right, p, q); // then move right and do same
        }
        if (cur > p->val && cur > q->val) {// if both nodes( p and q) value is smaller than root node value
            return lowestCommonAncestor(root->left, p, q); // then move left and do same
        }

        return root;
    }
};