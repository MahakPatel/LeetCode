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
    // +++++++++++++++++ Recursive Method ++++++++++++++++++++
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

    // // +++++++++++++ Iterative Method +++++++++++++++++++++
    // vector<int> inorderTraversal(TreeNode* root) {
    //     stack<TreeNode*> st; // create empty stack
    //     vector<int> inOrder; // for storing ans

    //     TreeNode* node = root; // craete node and assign to root

    //     while (true) {
    //         if (node != NULL) { // if node is not null
    //             st.push(node); // push that node into stack
    //             node = node->left; // and move left
    //         }else{
    //             if(st.empty()) break; // if stack empty break while loop and
    //             return node = st.top(); // get top node of the stack
    //             st.pop(); // pop out that niode
    //             inOrder.push_back(node->val); // push the value of that node
    //             node=node->right; // move right

    //         }
    //     }

    //     return inOrder;
    // }
};