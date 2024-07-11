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
    void solve(TreeNode* root, vector<int>& ans) {
        if (root == NULL) { // if root equal to zero return
            return;
        }

        // inOrder means (left,root,right)
        solve(root->left, ans);   // call function itself with left node
        ans.push_back(root->val); // push the node value into vector
        solve(root->right, ans);  // call function itself with right node
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; // create vector to store the answer
        solve(root, ans);
        return ans;
    }
};