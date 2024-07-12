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

//++++++++++++++++++++ Recursive +++++++++++++++++
    void solve(TreeNode* root, vector<int>& ans) {
        if (root == NULL) { // if root equal to zero return
            return;
        }

        // preorder means (root,left,right)
        ans.push_back(root->val); // push the node value into vector
        solve(root->left, ans);   // call function itself with left node
        solve(root->right, ans);  // call function itself with right node
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; // create vector to store the answer
        solve(root, ans);
        return ans;
    }
//+++++++++++++++ Itertive +++++++++++++++++
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> preOrder; // for storing ans
    //     if (root == NULL)
    //         return preOrder;

    //     stack<TreeNode*> st; // create empty stack

    //     st.push(root); // push root node

    //     while (!st.empty()) {
    //         root = st.top(); // get top of the stack
    //         st.pop();

    //         preOrder.push_back(root->val); // push root value into preOrder 

    //         if (root->right != NULL) // if right node is present 
    //             st.push(root->right); // push that node into stack
    //         if (root->left != NULL)// if left node is present 
    //             st.push(root->left);// push that node into stack
    //     }

    //     return preOrder;
    // }
};