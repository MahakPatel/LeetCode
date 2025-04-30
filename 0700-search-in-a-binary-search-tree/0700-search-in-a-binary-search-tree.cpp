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
TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && val != root->val){ // run till root is not NULL and val not found
            root = val<root->val ? root->left : root->right; // if value is less then the node  value then move left otherwise move right
        }

        return root;
    }
};