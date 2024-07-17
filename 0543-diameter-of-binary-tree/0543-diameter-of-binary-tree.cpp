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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0; // to store max path
        findLength(root,maxi);
        return maxi;
    }

    int findLength(TreeNode* root,int& maxi){
        if(root == NULL){
            return 0;
        }

        int left = findLength(root->left,maxi); // find the length of left 
        int right = findLength(root->right,maxi); // find the length of right

        maxi = max(maxi,left+right); // find the max path from the root node

        return (max(left,right) + 1);
    }
};