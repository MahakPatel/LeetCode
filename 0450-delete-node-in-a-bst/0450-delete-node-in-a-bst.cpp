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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) // check for root
            return NULL;

        if (root->val == key)// if the root node value is a key 
            return helper(root);

        TreeNode* temp = root; // create temp node top store root

        while (root != NULL) {
            if (root->val > key) { // if node value is gereater then key
                if (root->left != NULL && root->left->val == key) { // then move left
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else { // or else move right
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return temp;
    }
    // helper func use to connect right sub tree with the childs left sub tree
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){ // if left is null 
         return root->right; // return right
        }else if (root->right == NULL){// if right is null 
            return root->left;// return left
        }

        TreeNode* rightChild = root->right; // create one right node
        TreeNode* lastRight = findLastRight(root->left); // find the last node where we have to connect with right sub tree
        lastRight->right = rightChild; // connect right node of the given node with the last node right

        return root->left;
    }
// help to find the last node of right side
    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL) return root;

        return(findLastRight(root->right));
    }
};