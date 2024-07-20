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
        // base case
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q); // recursive call to left
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // recursive call to right

        if (left == NULL) {  // if left is NULL we can take right no matter what's value of right (it may be NULL)
            return right;
        } else if (right == NULL) { // if right is NULL we can take left no matter what's value of left (it may be NULL)
            return left;
        } else {
            return root; // if both left and right are not null,means we found our node
        }
    }
};