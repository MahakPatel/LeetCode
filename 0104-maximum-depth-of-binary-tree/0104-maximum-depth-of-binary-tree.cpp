/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL){ // if root is NULL
            return 0; // return lengrh =0
        }

        int left = maxDepth(root->left); // find the length of left nodes
        int right = maxDepth(root->right); // find the length of right nodes

        return 1 + max(left,right); // 1(currentNode) + maximum height of the side(left or right)
    }
};