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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0; // for vector traversal

        return buildBST(preorder, i, INT_MAX);
    }

    TreeNode* buildBST(vector<int>& preorder, int& i, int upperBound) {
        if (i == preorder.size() || preorder[i] > upperBound)
            return NULL; // if vector is empty or valu of vector is greater then
                         // upperbound

        TreeNode* root = new TreeNode(preorder[i++]); // create root node
        root->left =
            buildBST(preorder, i, root->val); // for left side upperBound is
                                              // always less then root value
        root->right = buildBST(
            preorder, i, upperBound); // for right side upper bound is max value
                                      // that possible or the root value of tree

        return root;
    }
};