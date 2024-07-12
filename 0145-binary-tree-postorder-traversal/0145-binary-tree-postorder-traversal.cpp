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
//++++++++++++++++ Recursive Method ++++++++++++++++++++++
    void solve(TreeNode* root, vector<int>& ans) {
        if (root == NULL) { // if root equal to zero return
            return;
        }

        // postOrder means (left,right,root)
        solve(root->left, ans);   // call function itself with left node
        solve(root->right, ans);  // call function itself with right node
        ans.push_back(root->val); // push the node value into vector
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans; // create vector to store the answer
        solve(root, ans);
        return ans;
    }

    //+++++++++++++++ Iterative Method +++++++++++++++

    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> postOrder; // for storing ans
    //     stack<TreeNode*> st1,st2; // craete 2 empty stack
    //     if(root == NULL) return postOrder;

    //     st1.push(root); // push root node in stack 1

    //     while(!st1.empty()){
    //         root = st1.top(); // get the top of the stack
    //         st1.pop();
    //         st2.push(root); // and push into st2
 
    //         if(root -> left != NULL) st1.push(root->left); // if left node is present then push into st1
    //         if(root -> right != NULL) st1.push(root->right);// if right node is present then push into st1
    //     }

    //     while(!st2.empty()){ // run till st2 become empty
    //         postOrder.push_back(st2.top()->val); // push stack 2 top into postOrder
    //         st2.pop(); // and pop out that node
    //     }

    //     return postOrder;
    // }
};