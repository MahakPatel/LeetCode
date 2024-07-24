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
    bool isValidBST(TreeNode* root) {
        long long minVal = LLONG_MIN; // Initialize to the smallest possible long long value
        long long maxVal = LLONG_MAX; // Initialize to the largest possible long long value

        // min value and max value is for range

        return isValidBST(root,minVal,maxVal);
    }

    bool isValidBST(TreeNode* root,long long minVal, long long maxVal){
        if(root == NULL) return true;

        if(root -> val >= maxVal || root->val <= minVal) return false; // if node value is greater then max value or node value if less then minvalue return false
 
        // call recursive func first left side with range(minVal to root val) and for right side range will (root  val to maxval)

        // for left side node valus should always between minvalue and root value
        // for right side node valus should always between root value and max value
        return isValidBST(root->left,minVal,root->val) && isValidBST(root->right,root->val,maxVal);
    }
    
};