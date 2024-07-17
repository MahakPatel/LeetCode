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
    bool isBalanced(TreeNode* root) {
        return heightOfTree(root) != -1; // if not -1 then return true otherwise return false
    }

    int heightOfTree(TreeNode* root){
        if( root == NULL) return 0;

        int left = heightOfTree(root -> left); // count length of left
        int right = heightOfTree(root -> right);// count length of right

        if(left == -1 || right == -1) return -1; // if any one value is -1 return false(-1)

        if(abs(right - left) > 1) return -1; // if absolute diff between right and left is grater than 1 then it is not balanced tree

        return (max(left,right) + 1); // right height
    }
};