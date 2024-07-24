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

// insert at leaf node
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val); // if root is null then create new node and return that node

        TreeNode* cur = root; // temp node

        while(true){
            if(cur->val <= val){ // if new node value is greater than root then right
                if(cur->right != NULL) cur = cur->right; // move right till root node value is not NULL
                else { 
                    cur->right = new TreeNode(val); // if root node value is NULL then create new node and break the loop
                    break;
                }
            }else{//if new node value is smaller than root then left
                if(cur->left != NULL) cur = cur->left;// move right till root node value is not NULL
                else{ 
                    cur->left = new TreeNode(val);// if root node value is NULL then create new node and break the loop
                    break;
                }
            }
        }

        return root;
    }
};