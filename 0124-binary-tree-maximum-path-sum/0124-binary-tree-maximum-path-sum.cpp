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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; // to store max sum of the node
        findSumOfPath(root,maxi);

        return maxi;
    }

    int findSumOfPath(TreeNode* root,int& maxi){
        if (root == NULL) return 0;

        int leftSum = max(0,findSumOfPath(root->left, maxi)); // find the sum of left nodes
        int rightSum = max(0,findSumOfPath(root->right, maxi)); // find the sun of right nodes

        maxi = max(maxi,leftSum + rightSum + root->val); // find the max sum of all the nodes

        return (root->val) + max(leftSum,rightSum); // return the sum of current node and max of leftSum and RightSum

    }
};